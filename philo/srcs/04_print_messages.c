/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_print_messages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:29:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/02 14:14:28 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This is the message that is printed out when philo dies
We lock the mutex "message" to make sure that no other message
is printed out. Once unlocked, no other messsage is printed out
because a condition in print_message function states that the status
must be different that DIED (if global->status != DIED) */
void	is_dying(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->global->message);
	printf("%lld ", timestamp_in_ms() - p->global->timestamp_start);
	printf("%d ", p->id);
	printf("%s", str);
	pthread_mutex_unlock(&p->global->message);
}

/*Message to be printed out when philo thinks*/
void	is_thinking(t_philo *p)
{
	print_message(p, "is thinking\n");
	//usleep(100);
	p->status = EAT;
}

/*Message to be printed out when philo sleeps*/
void	is_sleeping(t_philo *p)
{
	print_message(p, "is sleeping\n");
	sequential_usleep(p->global->time_to_sleep, p->global);
	p->status = THINK;
}

/* Message to be printed out, when philo eats. If philo
is 1, then we only take one fork, usleep for a time longer
than time_to_die and then dies. In other cases, philo eats.
mutex_lock for each fork so that no other philo can use same
forks. Mutex_lock when he eats to make sure meal_count keeps 
the right count*/
void	is_eating(t_philo *p)
{
	if (p->global->nb_philo == 1)
	{
		pthread_mutex_lock(&p->fork);
		print_message(p, "has taken a fork\n");
		usleep(p->global->time_to_die * 1100);
		pthread_mutex_unlock(&p->fork);
	}
	else
	{
		pthread_mutex_lock(&p->global->fork_checker);
		pthread_mutex_lock(&p->fork);
		print_message(p, "has taken a fork\n");
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_unlock(&p->global->fork_checker);
		print_message(p, "has taken a fork\n");
		print_message(p, "is eating\n");
		p->time_last_meal = timestamp_in_ms();
		sequential_usleep(p->global->time_to_eat, p->global);
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(p->right_fork);
		p->status = SLEEP;
	}
}

/* Function to print message. Uses lock and unlock to
make sure no other message appear. Also, 1st condition
prints that philo is eating and then prints that they all
ate (when all ate is at 0). In other cases, it prints the 
message that has been given as argument */
void	print_message(t_philo *p, char *str)
{	
	t_global	*g;

	g = p->global;
	pthread_mutex_lock(&g->message);
	if (g->status != DIED && g->status != DONE)
	{
		if (g->time_must_eat != 0 && p->nb_meal != g->time_must_eat)
		{
			printf("%lld ", timestamp_in_ms() - g->timestamp_start);
			printf("%d ", p->id);
			printf("%s", str);
			if (ft_strcmp(str, "is eating\n") == 0 && \
			p->nb_meal != g->time_must_eat)
			{
				g->meal_count--;
				p->nb_meal++;
			}
		}
		if (g->meal_count == 0)
		{
			g->status = DONE;
			printf("ALL PHILOSOPHERS ATE!!!\n");
		}
	}
	pthread_mutex_unlock(&g->message);
}

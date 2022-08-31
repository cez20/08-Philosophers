/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_start_philo_threads.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/31 12:42:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Message to be printed out when philo thinks*/
void	is_thinking(t_philo *p)
{
	print_message(p, "is thinking\n");
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
		pthread_mutex_lock(&p->fork);
		print_message(p, "has taken a fork\n");
		pthread_mutex_lock(p->right_fork);
		print_message(p, "has taken a fork\n");
		pthread_mutex_lock(&p->global->meal_tracker);
		p->global->meal_count--;
		print_message(p, "is eating\n");
		pthread_mutex_unlock(&p->global->meal_tracker);
		p->time_last_meal = timestamp_in_ms();
		sequential_usleep(p->global->time_to_eat, p->global);
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(p->right_fork);
		p->status = SLEEP;
	}
}

/*This function is the one that initiates all threads and 
that is called in pthread_create*/
void	*start(void *p)
{
	t_philo		*philo;

	philo = (t_philo *)p;
	if ((philo->id % 2) == 0)
		usleep(15000);
	while (philo->global->status != DIED)
	{
		if (philo->status == EAT)
			is_eating(philo);
		if (philo->global->status == DONE)
			break ;
		else if (philo->status == SLEEP)
			is_sleeping(philo);
		else if (philo->status == THINK)
			is_thinking(philo);
	}
	return (NULL);
}

/* This function initiliazes 1 thread per philosophers by using 
pthread_create.The "philo_thread" goes inside the function "start" 
to realize all acton in loop.Then, the "MAIN" thread updates the 
time_last_meal for current philo thread and then goes again in the loop 
to create the threads for all remaining philosophers*/
void	start_philo_threads(t_global *g)
{
	int	i;

	i = 0;
	g->timestamp_start = timestamp_in_ms();
	while (i < g->nb_philo)
	{	
		if (pthread_create(&g->philo[i]->thread, NULL, start, g->philo[i]) != 0)
			return ;
		g->philo[i]->time_last_meal = timestamp_in_ms();
		i++;
	}
}

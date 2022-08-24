/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/24 16:15:29 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_sleeping(t_philo *p)
{
	print_message(p, "is sleeping\n");
	sequential_usleep(p->global->time_to_sleep, p->global);
	p->status = THINK;
}

void	is_thinking(t_philo *p)
{
	print_message(p, "is thinking\n");
	p->status = EAT;
}

void	print_message(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->global->message);
	if (p->global->status != DIED)
	{
		printf("%lld ", timestamp_in_ms() - p->global->timestamp_start);
		printf("%d ", p->id);
		printf("%s", str);
	}	
	pthread_mutex_unlock(&p->global->message);
}

void	is_eating(t_philo *p)
{
	pthread_mutex_lock(&p->fork);
	print_message(p, "has taken a fork\n");
	pthread_mutex_lock(p->right_fork);
	print_message(p, "has taken a fork\n");
	print_message(p, "is eating\n");
	p->time_last_meal = timestamp_in_ms();
	sequential_usleep(p->global->time_to_eat, p->global);
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_unlock(p->right_fork);
	p->status = SLEEP;
}

/*This function is the one that initiates all threads and that is called in pthread_create*/
void	*start(void *p)
{
	t_philo		*philo;
	
	philo = (t_philo *)p;
	if ((philo->id % 2) == 0)
		usleep(15000);
	while(philo->global->status != DIED)
	{
		if (philo->status == EAT)
			is_eating(philo);
		else if (philo->status == SLEEP)
			is_sleeping(philo);
		else if (philo->status == THINK)
			is_thinking(philo);
	}
	return (NULL);
}

/* This function takes the double pointer **philo inside my data struct. This double_pointer points
to another structure that contains all the information regarding each philosophers. We malloc enough memory to
the double pointers so that it can accept all philo struct. Then, after we malloc each subelements so that it has enough
memory */

void	start_simulation(t_global *g)
{
	int 		i;

	i = 0;
	g->timestamp_start = timestamp_in_ms();
	while (i < g->nb_philo)
	{	
		if (pthread_create(&g->philo[i]->thread, NULL, start, g->philo[i]) != 0)
			return ;
		g->philo[i]->time_last_meal = timestamp_in_ms(); //Analyser a quoi ca sert exactement.
		i++; 
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_start_philo_threads.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/02 13:45:45 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*This function is the one that initiates all threads and 
that is called in pthread_create*/
void	*start(void *p)
{
	t_philo		*philo;

	philo = (t_philo *)p;
	if ((philo->id % 2) == 1)
		usleep(15000);
	//philo->time_last_meal = timestamp_in_ms();
	while (philo->global->status != DIED)
	{
		if (philo->status == EAT)
			is_eating(philo);
		if (philo->global->status == DONE)
			break ;
		//if (philo->nb_meal == philo->global->time_must_eat)
			//break ;
		else if (philo->status == SLEEP)
			is_sleeping(philo);
		else if (philo->status == THINK)
			is_thinking(philo);
	}
	printf("Philo[%d] a mange %d fois\n", philo->id, philo->nb_meal);
	return (NULL);
}

/* This function initiliazes 1 thread per philosophers by using 
pthread_create.The "philo_thread" goes inside the function "start" 
to realize all acton in loop.Then, the "MAIN" thread updates the 
time_last_meal for current philo thread and then goes again in the loop 
to create the threads for all remaining philosophers*/
int	start_philo_threads(t_global *g)
{
	int	i;

	i = 0;
	g->timestamp_start = timestamp_in_ms();
	while (i < g->nb_philo)
	{	
		if (pthread_create(&g->philo[i]->thread, NULL, start, g->philo[i]) != 0)
			return (1);
		g->philo[i]->time_last_meal = timestamp_in_ms();
		i++;
	}
	return (0);
}

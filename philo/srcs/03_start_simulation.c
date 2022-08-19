/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/19 17:01:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This function takes the double pointer **philo inside my data struct. This double_pointer points
to another structure that contains all the information regarding each philosophers. We malloc enough memory to
the double pointers so that it can accept all philo struct. Then, after we malloc each subelements so that it has enough
memory */

void	init_simulation(t_global *g)
{
	int 		i;

	i = 0;
	g->timestamp_start = timestamp_in_ms();
	while (i < g->nb_philo)
	{	
		if (pthread_create(&g->philo[i]->thread, NULL, start, g->philo[i]) ) != 0;
			return ;
		g->philo[i]->time_last_meal = timestamp_in_ms(); // Pourquoi le time_last_meal irait ici?
		i++; 
	}
}

// /*This function is the one that initiates all threads and that is called in pthread_create*/
// void	*start(void *philo)
// {
// 	t_philo		*p;

// 	p = (t_philo *)philo;
// 	if ((p->id % 2) == 0)
// 		usleep(15000);
// 	while(1)
// 	{
// 		philo_status(p);
// 		if (p->status == DYING)
// 		{
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// 	exit(EXIT_FAILURE);
// 	return (NULL);
// }

// void	philo_status(t_philo *p)
// {
// 	if (p->status == EATING)
// 		is_eating(p);
// 	else if (p->status == SLEEPING)
// 		is_thinking(p);
// 	else if (p->status == THINKING)
// 		is_thinking(p);
// }

// // I should put a lock on a message everytime I print one
// void	is_eating(t_philo *p)
// {
	
// 	pthread_mutex_lock(&p->fork);
// 	print_message(p, FORK);
// 	pthread_mutex_lock(&p->next_thread->fork);
// 	print_message(p, FORK);
// 	if ((timestamp_in_ms() - p->time_last_meal) < p->data->time_to_die)
// 	{
// 		//Normally I would need another mutex_lock here 
// 		print_message(p, EAT);
// 		p->time_last_meal = timestamp_in_ms();
// 		//mute_unlock here normally
// 		usleep(p->data->time_to_eat * 1000); // To get usleep in microseconds
// 		pthread_mutex_unlock(&p->fork);
// 		pthread_mutex_unlock(&p->next_thread->fork);
// 		p->status = SLEEPING;
// 	}
// 	else
// 	{
// 		p->status = DYING;
// 		print_message(p, DIE);
// 	}
// }

// void	is_sleeping(t_philo *p)
// {
// 	print_message(p, SLEEP);
// 	usleep(p->data->time_to_sleep * 1000);
// 	p->status = THINKING;
// }

// void	is_thinking(t_philo *p)
// {
// 	print_message(p, THINK);
// 	p->status = EATING;
// }

// void	print_message(t_philo *p, char *str)
// {
// 	pthread_mutex_lock(&p->data->message);
// 	printf("%lld ", timestamp_in_ms() - p->data->timestamp_start);
// 	printf("%d ", p->id);
// 	printf("%s", str);
// 	pthread_mutex_unlock(&p->data->message);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/20 15:46:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_sleeping(t_philo *p)
{
	print_message(p, SLEEP);
	usleep(p->global->time_to_sleep * 1000);
	p->status = THINKING;
}

void	is_thinking(t_philo *p)
{
	print_message(p, THINK);
	p->status = EATING;
}

void	print_message(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->global->message);
	printf("%lld ", timestamp_in_ms() - p->global->timestamp_start);
	printf("%d ", p->id);
	printf("%s", str);
	pthread_mutex_unlock(&p->global->message);
}

void	is_eating(t_philo *p)
{
	int current_timestamp;
	
	pthread_mutex_lock(&p->fork);
	print_message(p, FORK);
	current_timestamp = (timestamp_in_ms() - p->time_last_meal);
	printf("Current timestamp is %d\n", current_timestamp);
	if (p->right_fork != NULL && current_timestamp < p->global->time_to_die)
	{
		pthread_mutex_lock(p->right_fork);
		print_message(p, FORK);
		print_message(p, EAT);
		p->time_last_meal = timestamp_in_ms();
		usleep(p->global->time_to_eat * 1000); // To get usleep in microseconds
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(p->right_fork);
		p->status = SLEEPING;
	}
	else
	{
		p->status = DYING;
		p->global->status = DYING;
		print_message(p, DIE);
		pthread_mutex_unlock(&p->fork);
	}
}

/*This function is the one that initiates all threads and that is called in pthread_create*/
void	*start(void *p)
{
	t_philo		*philo;
	
	philo = (t_philo *)p;
	if ((philo->id % 2) == 0)
	{
		philo->status = THINKING;
		usleep(15000);
	}
	while(philo->global->status != DYING)
	{
		if (philo->status == EATING)
			is_eating(philo);
		else if (philo->status == SLEEPING)
			is_sleeping(philo);
		else if (philo->status == THINKING)
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
		g->philo[i]->time_last_meal = timestamp_in_ms(); // Ce time_last_meal serait exclusivement quand le philo meurt, car sinon il n'a aucun time_last_meal  
		i++; 
	}
}

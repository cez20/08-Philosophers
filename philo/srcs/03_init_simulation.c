/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/16 19:26:58 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This function takes the double pointer **philo inside my data struct. This double_pointer points
to another structure that contains all the information regarding each philosophers. We malloc enough memory to
the double pointers so that it can accept all philo struct. Then, after we malloc each subelements so that it has enough
memory */

void	init_simulation(t_data *p)
{
	int i;

	i = 0;
	while (i < p->nb_philo)
	{	
		pthread_create(&p->philo[i]->thread, NULL, start, (void *)p->philo[i]);
		//printf("Creation du thread :[%ld]\n", p->philo[i]->thread);
		i++; 
	}
	i = 0;
	while (i < p->nb_philo) // Loop pour attendre chacun des threads.
	{
		pthread_join(p->philo[i]->thread, NULL);
		i++;
	}
}

/*This function is the one that initiates all threads and that is called in pthread_create*/

void	*start(void *philo)
{
	t_philo		*p;
	pthread_t	thread;

	thread = pthread_self();
	p = (t_philo *)philo;
	pthread_mutex_lock(&p->fork);
		printf("Philosophe %d a pris sa fourchette\n", p->id);
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_destroy(&p->fork);
	return (NULL);
}



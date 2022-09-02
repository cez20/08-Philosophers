/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:02:49 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/02 00:53:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This function destroys the mutex, that were initialized in init_mutex,
   in order to leave the program in a clean way. */
int	destroy_mutex(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		if (pthread_mutex_destroy(&global->philo[i]->fork) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&global->message) != 0)
		return (1);
	if (pthread_mutex_destroy(&global->fork_checker) != 0)
		return (1);
	return (0);
}

/* This function inits all mutex necessary for completion of 
   this program:initialize mutex for forks, so that each time 
   a philosophers eats, the two forks he needs cannot be used 
   by another philosophers. Also, initializes mutex for message, 
   so that while message is printed out, no other message can come 
   out. */
int	init_mutex(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		if (pthread_mutex_init(&global->philo[i]->fork, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&global->message, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&global->fork_checker, NULL) != 0)
		return (1);
	return (0);
}

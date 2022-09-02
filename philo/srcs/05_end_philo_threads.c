/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_end_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:38:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/02 13:09:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This function waits for the specified thread to terminate. In
other words, even though the "MAIN THREAD" is in this function and
execute the while loop, the while loop will be on paused until the
thread [0] gets out the the "start" function loop. Then, we can initiate
the process of ending all threads*/
int	end_philo_threads(t_global *g)
{
	int	i;

	i = 0;
	while (i < g->nb_philo)
	{
		if (pthread_join(g->philo[i]->thread, NULL))
			return (1);
		pthread_mutex_destroy(&g->philo[i]->fork);
		i++;
	}
	pthread_mutex_destroy(&g->message);
	pthread_mutex_destroy(&g->fork_checker);
	free_struct(g);
	return (0);
}

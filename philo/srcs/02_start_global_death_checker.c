/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_start_global_death_checker.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:05:54 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/25 11:58:58 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*This function initialize the thread death_checker which is separate from
the philo_threads. This thread sole purpose is to continuously verify if the 
gapbetween the current_time and the philo_last_meal (or beginning of simulation) 
is bigger than the time_to_die. If the dealy is bigger than time_to_die than 
philo dies and status changed to DIED*/
void	*check_if_dead(void *global)
{
	t_global	*g;
	long long	current_time;
	int			i;

	g = (t_global *)global;
	while (g->status != DIED && g->status != DONE)
	{
		i = 0;
		while (i < g->nb_philo && g->status != DONE)
		{
			current_time = timestamp_in_ms();
			if ((current_time - g->philo[i]->time_last_meal) > g->time_to_die)
			{
				g->status = DIED;
				is_dying(g->philo[i], "died\n");
				usleep(100);
			}
			if (g->status == DIED)
				break ;
			i++;
		}
	}
	pthread_detach(g->death_checker);
	return (NULL);
}

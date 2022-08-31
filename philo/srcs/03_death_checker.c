/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_death_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:05:54 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/31 11:38:41 by cemenjiv         ###   ########.fr       */
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
		while (i < g->nb_philo)
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
	return (NULL);
}

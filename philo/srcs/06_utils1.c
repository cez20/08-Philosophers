/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:43:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/26 14:38:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*// Pourquoi le simple fait de mettre egal a cote de > change les secondes. */
void	sequential_usleep(long long total_time_for_action, t_global *g)
{
	long long	start_time;
	long long	current_updated_time;

	start_time = timestamp_in_ms();
	while (g->status != DIED)
	{
		current_updated_time = timestamp_in_ms();
		if ((current_updated_time - start_time) >= total_time_for_action)
			break ;
		usleep(50);
	}
}

void	free_struct(t_global *global)
{
	int	i;

	i = global->nb_philo - 1;
	while (i >= 0)
	{
		free(global->philo[i]);
		i--;
	}
	free(global->philo);
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

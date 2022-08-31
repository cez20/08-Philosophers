/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:43:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/30 21:05:58 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Pourquoi le simple fait de mettre egal a cote de > change les secondes. */
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
	t_global	*g;

	g = p->global;
	pthread_mutex_lock(&p->global->message);
	if (g->meal_count == 0 && g->status != DONE && g->status != DIED)
	{
		p->global->status = DONE;
		printf("%lld ", timestamp_in_ms() - p->global->timestamp_start);
		printf("%d ", p->id);
		printf("%s", str);
		printf("ALL PHILOSOPHERS ATE!!!\n");
	}
	else if (p->global->status != DIED && p->global->status != DONE)
	{
		printf("%lld ", timestamp_in_ms() - p->global->timestamp_start);
		printf("%d ", p->id);
		printf("%s", str);
	}
	pthread_mutex_unlock(&p->global->message);
}

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

void	is_dying(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->global->message);
	printf("%lld ", timestamp_in_ms() - p->global->timestamp_start);
	printf("%d ", p->id);
	printf("%s", str);
	pthread_mutex_unlock(&p->global->message);
}

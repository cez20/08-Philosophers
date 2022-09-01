/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:43:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/01 17:59:48 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Funciton to free all pointer or double pointer that have
been malloced*/
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

/* This function replaces the regular usleep. It is more precise.
It splits the time_to_eat or time_to_sleep into minisequence of
50 microseconds instead of a for example a full period of 200
microseconds. The reason behind this, is because after 50 microseconds,
the status of a philo could changed to DIED, and by doing so, we don't need
the full period to be over, because after 50 seconds we know it*/
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

/* Function to print message. Uses lock and unlock to
make sure no other message appear. Also, 1st condition
prints that philo is eating and then prints that they all
ate (when all ate is at 0). In other cases, it prints the 
message that has been given as argument */
void	print_message(t_philo *p, char *str)
{	
	t_global	*g;

	g = p->global;
	pthread_mutex_lock(&g->message);
	//if (g->status != DONE && g->status != DIED)
	if ((g->status != DIED) && (p->meal != g->time_must_eat))
	{
		if (g->time_must_eat != 0)
		{
			printf("%lld ", timestamp_in_ms() - g->timestamp_start);
			printf("%d ", p->id);
			printf("%s", str);
			if (ft_strcmp(str, "is eating\n") == 0 && \
			p->meal != g->time_must_eat)
			{
				g->meal_count--;
				p->meal++;
			}
		}
		if (g->meal_count == 0)
		{
			g->status = DONE;
			printf("ALL PHILOSOPHERS ATE!!!\n");
		}
	}
	pthread_mutex_unlock(&g->message);
}

/*Fonction to calculate timestamp in milliseconds
tv.sec is data in seconds. We multiply it by 1000 to get
milliseconds. tv_usec in microsecond. Divide it by 1000
to get milliseconds*/
long long	timestamp_in_ms(void)
{
	struct timeval		time;
	long long			timestamp;

	gettimeofday(&time, NULL);
	timestamp = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (timestamp);
}

/* Error message on stderr*/
int	error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

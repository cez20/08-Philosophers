/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/30 16:55:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_thinking(t_philo *p)
{
	print_message(p, "is thinking\n", YEL);
	p->status = EAT;
}

void	is_sleeping(t_philo *p)
{
	print_message(p, "is sleeping\n", BLUE);
	sequential_usleep(p->global->time_to_sleep, p->global);
	p->status = THINK;
}

void	is_eating(t_philo *p)
{
	if (p->global->nb_philo == 1)
	{
		pthread_mutex_lock(&p->fork);
		print_message(p, "has taken a fork\n", GRN);
		usleep(p->global->time_to_die * 1100);
		pthread_mutex_unlock(&p->fork);
	}
	else
	{
		pthread_mutex_lock(&p->fork);
		print_message(p, "has taken a fork\n", GRN);
		pthread_mutex_lock(p->right_fork);
		print_message(p, "has taken a fork\n", GRN);
		pthread_mutex_lock(&p->global->all_ate);
		p->global->all_philo_ate--;
		print_message(p, "is eating\n", GRN);
		printf("the all philo_ate is at: %d\n", p->global->all_philo_ate);
		pthread_mutex_unlock(&p->global->all_ate);
		p->time_last_meal = timestamp_in_ms();
		sequential_usleep(p->global->time_to_eat, p->global);
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(p->right_fork);
		p->status = SLEEP;
	}
}

/*This function is the one that initiates all threads and 
that is called in pthread_create*/
void	*start(void *p)
{
	t_philo		*philo;

	philo = (t_philo *)p;
	if ((philo->id % 2) == 0)
		usleep(15000);
	while (philo->global->status != DIED && philo->global->all_philo_ate > 0)
	{
		if (philo->status == EAT)
			is_eating(philo);
		if (philo->global->all_philo_ate <= 0)
			break ;
		else if (philo->status == SLEEP)
			is_sleeping(philo);
		else if (philo->status == THINK)
			is_thinking(philo);
	}
	// if (philo->global->status != DONE && philo->global->status != DIED)
	// {
	// 	philo->global->status = DONE;
	// 	print_message(philo, "ALL PHILOSOPHERS ATE\n", RED);
	// }
	return (NULL);
}

/* This function takes the double pointer **philo inside my data struct. 
This double_pointer points to another structure that contains all the 
information regarding each philosophers. We malloc enough memory to the
double pointers so that it can accept all philo struct. Then, after we 
malloc each subelements so that it has enough memory */
void	start_simulation(t_global *g)
{
	int	i;

	i = 0;
	g->timestamp_start = timestamp_in_ms();
	while (i < g->nb_philo)
	{	
		if (pthread_create(&g->philo[i]->thread, NULL, start, g->philo[i]) != 0)
			return ;
		g->philo[i]->time_last_meal = timestamp_in_ms();
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/29 13:12:27 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_thinking(t_philo *p)
{
	print_message(p, "is thinking\n");
	p->status = EAT;
}

void	is_sleeping(t_philo *p)
{
	print_message(p, "is sleeping\n");
	sequential_usleep(p->global->time_to_sleep, p->global);
	p->status = THINK;
}

void	is_eating(t_philo *p)
{
	if (p->global->nb_philo == 1)
	{
		pthread_mutex_lock(&p->fork);
		print_message(p, "has taken a fork\n");
		usleep(p->global->time_to_die * 1100);
		pthread_mutex_unlock(&p->fork);
	}
	else
	{
		pthread_mutex_lock(&p->fork);
		print_message(p, "has taken a fork\n");
		pthread_mutex_lock(p->right_fork);
		print_message(p, "has taken a fork\n");
		pthread_mutex_lock(&p->global->all_ate); // Proteger la variable, car sinon elle n'attendrait pas le bon chiffre
		print_message(p, "is eating\n"); //Ajouter cette section
		p->global->all_philo_ate--; // Ajouter cette section
		printf("Le nombre de fois que all_eat est:%d\n", p->global->all_philo_ate);// Ajouter cette section
		pthread_mutex_unlock(&p->global->all_ate); //Ajouter cette section 
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
	while (philo->global->status != DIED)
	{
		if (philo->status == EAT)
			is_eating(philo);
		if (philo->global->all_philo_ate == 0) // Condition ayant ete rajoute 
			break; // Condition ayant ete rajoute 
		else if (philo->status == SLEEP)
			is_sleeping(philo);
		else if (philo->status == THINK)
			is_thinking(philo);
	}
	if (philo->global->status != DONE && philo->global->status != DIED) // CEtte section a ete rajoute 
	{
		philo->global->status = DONE; // Section rajoute 
		print_message(philo, "All philo have eaten\n"); //Section rajoute
	}
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

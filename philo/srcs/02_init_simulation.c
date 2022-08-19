/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/18 20:53:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This function takes the double pointer **philo inside my data struct. This double_pointer points
to another structure that contains all the information regarding each philosophers. We malloc enough memory to
the double pointers so that it can accept all philo struct. Then, after we malloc each subelements so that it has enough
memory */

void	init_simulation(t_data *p)
{
	int 		i;

	i = 0;
	p->timestamp_start = timestamp_in_ms();
	while (i < p->nb_philo)
	{	
		if (i == (p->nb_philo - 1)) // Pour une raison inconnue, cette condition n'est pas obligatoire
			p->philo[i]->next_thread = p->philo[0]; // Pour une raison inconnue, non-necessaire
		pthread_create(&p->philo[i]->thread, NULL, start, p->philo[i]);
		p->philo[i]->time_last_meal = timestamp_in_ms();
		i++; 
	}
}

/*This function is the one that initiates all threads and that is called in pthread_create*/
void	*start(void *philo)
{
	t_philo		*p;

	p = (t_philo *)philo;
	if ((p->id % 2) == 0)
		usleep(15000);
	while(p->status != DYING) // while (1)
	{
		philo_status(p);
		break; //Enlever ce break, une fois toutes les conditions faites. 
	}	
	return (NULL);
}

void	philo_status(t_philo *p)
{
	if (p->status == EATING)
		is_eating(p);
	else if (p->status == SLEEPING)
		is_thinking(p);
	else if (p->status == THINKING)
		is_thinking(p);
}

// I should put a lock on a message everytime I print one
void	is_eating(t_philo *p)
{
	pthread_mutex_lock(&p->fork);
	print_message(p, FORK);
	pthread_mutex_lock(&p->next_thread->fork);
	print_message(p, FORK);
	//Normally I would need another mutex_lock here 
	print_message(p, EAT);
	p->time_last_meal = timestamp_in_ms();
	//mute_unlock here normally
	usleep(p->data->time_to_eat * 1000); // To get usleep in microseconds
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_unlock(&p->next_thread->fork);
	p->status = SLEEPING;
}

void	is_sleeping(t_philo *p)
{
	print_message(p, SLEEP);
	usleep(p->data->time_to_sleep * 1000);
	p->status = THINKING;
}

void	is_thinking(t_philo *p)
{
	print_message(p, THINK);
	p->status = EATING;
}

void	print_message(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->data->message);
	printf("%lld ", timestamp_in_ms() - p->data->timestamp_start);
	printf("%d ", p->id);
	printf("%s", str);
	pthread_mutex_unlock(&p->data->message);
}
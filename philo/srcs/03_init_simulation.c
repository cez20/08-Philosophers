/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/17 15:11:33 by cemenjiv         ###   ########.fr       */
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
	while (i < p->nb_philo)
	{	
		p->philo[i]->next_thread = p->philo[i + 1];
		if (i == (p->nb_philo - 1)) // Pour une raison inconnue, cette condition n'est pas obligatoire
			p->philo[i]->next_thread = p->philo[0];
		pthread_create(&p->philo[i]->thread, NULL, start, p->philo[i]);
		i++; 
	}
	i = 0;
	while (i < p->nb_philo) // Loop pour attendre chacun des threads.
	{
		pthread_join(p->philo[i]->thread, NULL);
		i++;
	}
}

/*This function is the one that initiates all threads and that is called in pthread_create*/
void	*start(void *philo)
{
	t_philo		*p;


	p = (t_philo *)philo;
	p->time_last_meal = p->data->timestamp;
	if ((p->index % 2) == 0)
		usleep(15000);
	while(1)
	{
		philo_status(p);
		if (p->status == DIED)
			break;
	}	
	return (NULL);
}

void	philo_status(t_philo *p)
{
	init_time(p->data);
	if (p->status == THINK)
		grab_first_fork(p);
	else if (p->status == FIRST_FORK)
		grab_second_fork(p);
	else if (p->status == SECOND_FORK)
		is_eating(p);
}


//Est-ce que je dois mettre a jour mon timestamp au debut de cette fonction 
void	grab_first_fork(t_philo *p)
{
	p->time_last_meal = p->data->timestamp;
	pthread_mutex_lock(&p->fork);
	printf("%d %d has taken a fork\n", p->time_last_meal, p->id);
	usleep(15000); // A valider si c'est correct
	p->status = FIRST_FORK;
}

void	grab_second_fork(t_philo *p)
{
	init_time(p->data);
	p->time_last_meal = p->data->timestamp;
	pthread_mutex_lock(&p->next_thread->fork);
	printf("%d %d has taken a fork\n", p->time_last_meal, p->id);
	usleep(15000); // A valider si c'est correct.  
	p->status = SECOND_FORK;
}

void	is_eating(t_philo *p)
{
	pthread_mutex_lock(&p->data->message);
	printf("%d %d is eating\n", p->time_last_meal, p->id);
	pthread_mutex_unlock(&p->data->message);
	usleep(p->data->time_to_eat * 1000);
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_unlock(&p->next_thread->fork);
}

// Fonction test pour un seul philosophers 
// void	one_philo()
// {
// 	long long	timestamp_start;
// 	int			new_timestamp;
	
// 	timestamp_start = get_time_in_ms();
// 	if (p->nb_philo == 1)
// 	{
// 		pthread_mutex_lock(&p->philo[i]->fork);
// 		p->philo[i]->time_last_meal = p->timestamp;
// 		printf("%d %d has taken a fork\n", p->philo[i]->time_last_meal, p->philo[i]->id);
// 		while (1)
// 		{
// 			if (p->philo[i]->status == THINK)
// 			{
// 				new_timestamp = get_time_in_ms() - timestamp_start;
// 				if (new_timestamp > p->time_to_die)
// 					break;
// 			}
			
// 		}
// 		pthread_mutex_unlock(&p->philo[i]->fork);
// 		printf("%d %d died\n", new_timestamp, p->philo[i]->id);
// 		exit(EXIT_FAILURE);
// 	}
// }
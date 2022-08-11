/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/10 14:27:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	sleep(2);
	printf("Hello World!\n");
	return (NULL);
}

void	finish_thread(t_thread *thread)
{
	int i;
	
	i = 0;
	while (i < thread->nb_philo)
	{
		if (pthread_join(thread->philo[i], NULL) != 0)
			return ;
		printf("Philo %d has finished execution\n", i + 1);
		i++;
	}
	pthread_mutex_destroy(&thread->mutex);
}

void	create_thread(t_thread *thread)
{
	int i;

	thread->philo = malloc(thread->nb_philo * sizeof(thread->philo)); // A valider le sizeof ici 
	thread->fork = malloc(thread->nb_philo * sizeof(thread->fork));
	if (!thread->philo)
		return ;
	i = 0;
	pthread_mutex_init(&thread->mutex, NULL);
	while (i < thread->nb_philo)
	{
		if (pthread_create(&thread->philo[i], NULL, &routine, NULL) != 0)
			return ;
		thread->fork[i] = 0; //Chaque fork contient le chiffre '0'. On y mettra 1 lorsqu'elle est en utilisation
		printf("Philo %d has started\n", i + 1);
		i++;
	}
}

void	create_data(t_thread *thread, char **argv)
{
	thread->nb_philo = ft_atoi(argv[1]);
	thread->time_to_die = ft_atoi(argv[2]);
	thread->time_to_eat = ft_atoi(argv[3]);
	thread->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		thread->time_must_eat = ft_atoi(argv[5]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/03 16:49:04 by cemenjiv         ###   ########.fr       */
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

void	create_thread(t_thread *thread, char **argv)
{
	int i;

	thread->nb_philo = ft_atoi(argv[1]);
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
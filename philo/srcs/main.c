/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/02 13:52:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Main function:
//pthread_t creates the variable necessary when creating thread with pthread_create.
//pthread_mutex_t create the variable necessary to create a mutex with p_thread_mutex_init(protection so that not many thread access info)
//First while loop allows us to create 1 thread per philosophers
//Second while loop call a "wait" with pthread_join so it wait for each thread to finish before going to next one.

void	*routine(void *mails)
{

	(*(int *)mails)++;
	sleep(3);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	mutex;
	pthread_t		*philo;
	int				nb_philo;
	int				i;
	int 			mails;

	i = 0;
	mails = 0;
	if (argc == 5 || argc == 6)
	{
		pthread_mutex_init(&mutex, NULL);
		nb_philo = atoi(argv[1]);
		philo = malloc((nb_philo + 1) * sizeof(int));
		if (!philo)
			return (1);
		while (i < nb_philo)
		{
			if (pthread_create(&philo[i], NULL, &routine, (void *)&mails) != 0)
				return (1);
			printf("Value of mails is %d\n", mails);
			i++;
		}
		i = 0;
		while (i < nb_philo)
		{
			if (pthread_join(philo[i], NULL) != 0)
				return (2);
			printf("Thread %d has finished execution\n", i);
			i++;
		}
	}
	else
		printf("Error\n");
	return (0);
}

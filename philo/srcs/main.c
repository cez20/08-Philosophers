/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/22 14:04:46 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t mutex;

void	*routine() // Fonction bidon utilise dans le pthread_create ici-bas. 
{
	int i;
	int mails;
	int *result;
	
	i = 0;
	mails = 0;
	result = malloc(sizeof(int)); // Necessary to dynamically allocated a vairable if we want its result to be returned in main function.  
	while (i < 10000)
	{
		pthread_mutex_lock(&mutex); //Protection pour eviter que d'autres threads ne viennent lire et ecrire donnee
		mails++;
		pthread_mutex_unlock(&mutex);//Enleve la protection;
		i++; 
	}
	*result = mails;
	printf("%p\n", result);
	return ((void *)result);
}

int main (int argc, char **argv) // Current main function is not working. Simpl giving an idea of what to do.  
{
	(void)argc;
	pthread_t philo;
	int nb_philosophers;
	int i;
	int *result;
	
	pthread_mutex_init(&mutex, NULL);
	nb_philosophers = atoi(argv[1]);
	philo = malloc(nb_philosophers * sizeof(int)); //malloc enough size for array 
	i = 0;
	while (i < nb_philosophers) // Create a thread for each philosophers. 
	{
		if (pthread_create(&philo, NULL, &routine, NULL) != 0) 
		{
			perror("Failed to create thread");
			return 1;
		}
		i++;	
	}
	i--;
	while (i >= 0) // Wait for each thread.
	{
		if (pthread_join(philo, (void**)&result) != 0) //
			return 2;
		printf("%p\n", result);
		i--;
	}

}
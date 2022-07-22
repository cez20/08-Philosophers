/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:42:31 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/22 10:27:15 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Video entitled "How to create threads in a loop"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	//read mails
	//increment
	//write mails
}

int main(int argc, char **argv) // Correct way of doing multithread
{
	int i;
	pthread_t th[4]; // Variable to type tpthread that will contain  
	
	pthread_mutex_init(&mutex, NULL); // initialize a mutex 
	for(i = 0; i < 4; i++)
	{
		if (pthread_create (&th[i], NULL, &routine, NULL) != 0) // in order to protect
		{
			perror("Failed to create thread\n");
			return 1;  // Allow to initialize the thread.
		}
		printf("Thread %d has started\n", i);
		
	}
	for(i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return 2;
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex); // Destroys the mutex
	printf("Number of mails is: %d\n", mails);
	return (0);
}

// int main(int argc, char **argv) // This first version does 1 thread at a time which is not the purpose of multithread 
// {
// 	int i;
// 	pthread_t th[4]; // Variable to type tpthread that will contain  
	
// 	pthread_mutex_init(&mutex, NULL); // initialize a mutex 
// 	for(i = 0; i < 4; i++)
// 	{
// 		if (pthread_create (&th[i], NULL, &routine, NULL) != 0) // in order to protect
// 		{
// 			perror("Failed to create thread\n");
// 			return 1;  // Allow to initialize the thread.
// 		}
// 		printf("Thread %d has started\n", i);
// 		if (pthread_join(th[i], NULL) != 0)
// 			return 2;
// 		printf("Thread %d has finished execution\n", i);
		
// 	}
// 	pthread_mutex_destroy(&mutex); // Destroys the mutex
// 	printf("Number of mails is: %d\n", mails);
// 	return (0);
// }
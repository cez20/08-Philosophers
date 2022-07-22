/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:16:35 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/20 13:47:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main(int argc, char **argv)
{
	pthread_t t1; // Variable to type tpthread that will contain  
	pthread_t t2;
	pthread_mutex_init(&mutex, NULL); // initialize a mutex 

	if (pthread_create (&t1, NULL, &routine, NULL) != 0) // in order to protect
		return 1;  // Allow to initialize the thread. 
	if (pthread_create (&t2, NULL, &routine, NULL) != 0)
		return 2;  // Allow to initialize the thread. pthread_create (&t2, NULL, &routine, NULL); 
	if (pthread_join(t1, NULL) != 0)
		return 3; // Essentially tha same as wait (for processes) but this is for threads. 
	if (pthread_join(t2, NULL) != 0)
		return 4;
	pthread_mutex_destroy(&mutex); // Destroys the mutex
	printf("Number of mails is: %d\n", mails);
	return (0);
}
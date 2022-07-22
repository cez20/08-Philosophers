/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:28:02 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/22 11:02:46 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Video entitled "How to pass arguments to threads in C"
//Problem to solve : Create 10 threads, each taking a unique prime from the primes array and print it on screen
//All numbers are not shown in order since it is a multithread.
// See how we can actually maybe put a mutex on this, so that all numbers are in order.  
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};


void*	routine(void *arg)
{
	sleep(1);
	int index;

	index = *(int *)arg;
	printf("%d\n", primes[index]);
	free(arg); //We free the "a" in our main function here. 
}


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	pthread_t th[10];
	int i;
	int *a;

	i = 0;
	while (i < 10)
	{
		a = malloc(sizeof(int));
		*a = i; // We must free this pointer
		if(pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("Failed to create thread");
		i++;
		//We cannot free pointer here because, we are not guaranteed that thread is finished her.e 
	}
	i = 0;
	while (i < 10)
	{
		if(pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
		i++;
	}
	return 0;
}
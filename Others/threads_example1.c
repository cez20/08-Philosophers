/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_example1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:08:31 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/22 11:31:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//video is entitled "Practical examples for using threads #1"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void*	routine(void *arg)
{
	int index;
	int sum;
	int j;

	index = *(int *)arg;
	sum = 0;
	j = 0;
	while(j < 5)
	{
		sum += primes[index + j];
		j++;
	}
	printf("Local sum: %d\n", sum);
	*(int *)arg = sum;
	return arg; 
}


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	pthread_t th[2];
	int i;
	int *a;
	int	*result;
	int globalSum;

	i = 0;
	result = 0;
	while (i < 2)
	{
		a = malloc(sizeof(int)); // Why passing a pointer here solves the problem?? 
		*a = i * 5; // We must free this pointer
		if(pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("Failed to create thread");
		i++;
		//We cannot free pointer here because, we are not guaranteed that thread is finished her.e 
	}
	i = 0;
	globalSum = 0;
	while (i < 2)
	{
		if(pthread_join(th[i], &result) != 0)
			perror("Failed to join thread");
		i++;
		globalSum += *result;
		free (result);
	}
	printf("Global sum: %d\n", globalSum);
	return 0;
}
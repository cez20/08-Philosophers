/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:26:05 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/19 14:05:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// When you compile the program you have to use the flag -pthread.
// For more information, see 'man phtread' 
// Rendu a 6:38

void *routine()
{
	printf("Test from threads\n");
	sleep(3);
	printf("Ending thread\n");
}

int main(int argc, char **argv)
{
	pthread_t t1; // Variable to type tpthread that will contain  
	pthread_t t2;

	if (pthread_create (&t1, NULL, &routine, NULL) != 0) // in order to protect
		return 1;  // Allow to initialize the thread. 
	if (pthread_create (&t2, NULL, &routine, NULL) != 0)
		return 2;  // Allow to initialize the thread. pthread_create (&t2, NULL, &routine, NULL); 
	if (pthread_join(t1, NULL) != 0)
		return 3; // Essentially tha same as wait (for processes) but this is for threads. 
	if (pthread_join(t2, NULL) != 0)
		return 4; 
	// To pass in the function 'routine' as a parameter, we have tgo 
	return (0);
}
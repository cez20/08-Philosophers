/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:02:29 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/22 10:25:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Video "Get return value from a thread(pthread_join)"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *roll_dice()
{
	int value = (rand() % 6) + 1;
	int *result; 
	result = malloc (sizeof(int)); //Returned value is dynamically allocated 
	*result = value;
	//printf("%d\n", value);
	//return (void *)&value; // This can work because it is a reference to a local value of this function. 
	printf("Thread result: %p\n", result);
	return (void *)result; // On se doit d'envoyer un pointeur et non une variable locale.  
}

int main(int argc, char **argv) // Correct way of doing multithread
{
	int i;
	int *res;
	srand(time(NULL));
	pthread_t th; 

	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return 1;
	if (pthread_join(th, (void **)&res) != 0) // Le "wait" on devra envoyer un double pointeur. CE double pointeur contiendra valeur retourne dans la fonction.
		return 2;
	printf("Main result: %p\n", res);
	printf("Result: %d\n", *res);
	free(res);
	return (0);
}

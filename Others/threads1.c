/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:11:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/19 14:28:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine()
{
	x++;
	sleep(2);
	printf("Value of x is %d\n", x);
}

void *routine2()
{
	sleep(2);
	printf("Value of x is %d\n", x);
}

int main (int argc, char **argv)
{
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL))
		return 1;
	if (pthread_create(&t1, NULL, &routine2, NULL))
		return 2;
	if (pthread_join(t1, NULL))
		return 3;
	if (pthread_join(t2, NULL))
		return 4;
	return 0;
}
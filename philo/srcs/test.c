/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:58:24 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/29 11:48:18 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//On peut compiler le programme en mettant les flags gcc -fsanitize=thread -g threads.c && ./a.out
//This function prints the initial data at the beginning of program 
void	print_initial_values(t_global *g)
{
	int i;

	printf("There are [%d] philosophers in total for this program\n", g->nb_philo);
	printf("The time_to die in milliseconds is [%d] for this program\n", g->time_to_die);
	printf("The time_to eat in milliseconds is [%d] for this program\n", g->time_to_eat);
	printf("The time_to sleep in milliseconds is [%d] for this program\n", g->time_to_sleep);
	printf("\n");
	
	i = 0;
	while (i < g->nb_philo)
	{
		printf("The status of philosopher is [%d].\n", g->philo[i]->status);
		printf("The index %d philosopher id is [%d].\n", i, g->philo[i]->id);
		//printf("The philosopher has eaten [%d] times.\n", g->philo[i]->nb_time_ate);
		printf("The philosophers last meal is at [%lld] (in milliseconds) from start.\n", g->philo[i]->time_last_meal);
		printf("\n");
		i++;		
	}
}

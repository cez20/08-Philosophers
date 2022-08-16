/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:58:24 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/16 17:37:22 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* The list of all functions that can be found here are essentially to test
the whole program during its execution. A small description under each section 
will be found. */ 

//On peut compiler le programme en mettant les flags gcc -fsanitize=thread -g threads.c && ./a.out


//This function prints the initial data at the beginning of program 
void	print_initial_data(t_data *p)
{
	int i;

	printf("There are [%d] philosophers in total for this program\n", p->nb_philo);
	printf("The time_to die in millisecond is [%d] for this program\n", p->time_to_die);
	printf("The time_to eat in millisecond is [%d] for this program\n", p->time_to_eat);
	printf("The time_to sleep in millisecond is [%d] for this program\n", p->time_to_sleep);
	
	i = 0;
	while (i < p->nb_philo)
	{
		printf("The index %d philosopher id is [%d].\n", i, p->philo[i]->id);
		printf("The philosopher has eaten [%d] times.\n", p->philo[i]->nb_time_eat);
		printf("The philosophers last meal is at [%d] (in milliseconds) from start.\n", p->philo[i]->time_last_meal);
		i++;		
	}
}




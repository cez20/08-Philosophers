/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:03:38 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/17 08:07:19 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*This function validates that each argv is correct, by calling
the function valid int. It also malloc enough memory for each philo struct*/

void	init_data(t_data *data, char **argv)
{
	data->nb_philo = valid_int(argv[1]);
	data->time_to_die = valid_int(argv[2]);
	data->time_to_eat = valid_int(argv[3]);
	data->time_to_sleep = valid_int(argv[4]);
	if (argv[5])
		data->time_must_eat = valid_int(argv[5]);
	else
		data->time_must_eat = -1;
	if (data->nb_philo == 0)
		error(ERR_PHILO);
	malloc_philo(data);
	//print_initial_data(data); Function to prints initial data. For tests only
}

/*This function validations, that all arguments are digits and secondly 
that each arguments is not negative. In some instances, it happens that 
when you inset a positive integer beyond INT_MAX and does return a
negative value. This is why the nb < 0 is in place.*/

int	valid_int(char *argv)
{
	int i;
	int nb;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) != 1)
			error(ERR_DATA);
		i++;
	}
	nb = ft_atoi(argv);
	if (nb < 0)
		error(ERR_DATA);	
	return (nb);
}


/* This function malloc enough memory is a double pointer. It first malloc the t_philo double pointer
so that each index contains a pointer to its own t_philo struct (t_philo *). Then, we malloc each index
so that it gets enough memory to contain all data of the struct. Initiate a mutex as well */

void	malloc_philo(t_data *p)
{
	int i;

	p->philo = malloc(p->nb_philo * sizeof(t_philo *)); //verifier que le sizeof est bon. 
	if (!p->philo)
		return ;
	i = 0;
	while (i < p->nb_philo)
	{	
		p->philo[i] = malloc(sizeof(t_philo)); // Verifier que le sizeof est bon
		if (!p->philo[i])
			return ;
		pthread_mutex_init(&p->philo[i]->fork, NULL);
		p->philo[i]->id = i + 1; 
		p->philo[i]->nb_time_eat = 0;
		p->philo[i]->time_last_meal = 0;
		p->philo[i]->status = THINK;
		p->philo[i]->data = malloc(sizeof(t_data));
		i++; 
	}
}
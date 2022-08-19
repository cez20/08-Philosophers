/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:03:38 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/19 14:51:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This function mallocs enought memory for a 2d array. First malloc is to
   malloc an array that will contain "global->nb_philo" pointers of type t_philo. 
   Second malloc, gives enough memory to contain all variables that can be found
   inside the t_philo struct and assign a value to each of its variable. */

void	init_each_philo(t_global *global)
{
	int	i;

	global->philo = malloc(global->nb_philo * sizeof(t_philo *));
	if (!global->philo)
		return ;
	i = 0;
	while (i < global->nb_philo)
	{
		global->philo[i] = malloc(sizeof(t_philo));
		if (!global->philo[i])
			return ;
		global->philo[i]->status = EATING;
		global->philo[i]->id = (i + 1);
		global->philo[i]->own_fork = i;
		global->philo[i]->nb_time_ate = 0;
		global->philo[i]->time_last_meal = 0;
		global->philo[i]->global = global;
		if (i == (global->nb_philo - 1))
			global->philo[i]->right_fork = 0;
		else
			global->philo[i]->right_fork = (i + 1);
		i++;
	}
}

/* This function creates an "array" of forks of type pthread_mutex_t. For example,
   if we have 30 philosophers, it creates an array of 30 forks of type pthread_mutex_t */

void	init_global_forks(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{	
		global->fork = malloc(global->nb_philo * sizeof(global->fork));
		if (!global->fork)
			return ;
		i++;
	}
}

/*This function validations, that all arguments are digits and secondly 
that each arguments is not negative. In some instances, it happens that 
when you inset a positive integer beyond INT_MAX and does return a
negative value. This is why the nb < 0 is in place. */

int	valid_int(char *argv)
{
	int	i;
	int	nb;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) != 1)
			error(ERR_DATA);
		i++;
	}
	nb = ft_atoi(argv);
	if (nb < 0)
		error (ERR_DATA);
	return (nb);
}

/* This function initializes all the basic variables inside the t_global struct */

void	init_global_variables(t_global *global, char **argv)
{
	global->nb_philo = valid_int(argv[1]);
	global->time_to_die = valid_int(argv[2]);
	global->time_to_eat = valid_int(argv[3]);
	global->time_to_sleep = valid_int(argv[4]);
	if (argv[5])
		global->time_must_eat = valid_int(argv[5]);
	else
		global->time_must_eat = -1;
	if (global->nb_philo == 0)
		error(ERR_PHILO);
}

/*This function wraps up all functions that initialize the data:
  1- init_global_variables inits all variables that are not pointers that are gound in t_global struct.
  2- init_global_forks inits the forks that are found in t_global struct.
  3- init_each philo mallocs each philosophers (t_philo struct) and the data it contains.*/

void	init_variables(t_global *global, char **argv)
{
	init_global_variables(global, argv);
	init_global_forks(global);
	init_each_philo(global);
	print_initial_values(global);
}

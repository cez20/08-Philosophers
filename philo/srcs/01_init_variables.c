/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:03:38 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/01 17:20:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*This function identifies the right fork of each philosophers
  If there is only 1 philosopher, right fork is non-existing. If
  philo id corresponds to the total number of philos, then the right 
  forks the  first' philosophers(philo[0]). In all other cases, it is the philo 
  on the right (philo[i + 1]) */
void	philo_right_fork(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		if (global->nb_philo == 1)
			global->philo[i]->right_fork = NULL;
		else if (i == (global->nb_philo - 1))
			global->philo[i]->right_fork = &(global->philo[0]->fork);
		else
			global->philo[i]->right_fork = &(global->philo[i + 1]->fork);
		i++;
	}
}

/* This function mallocs enought memory for a 2d array. 
   First malloc is to malloc an array that will contain 
   "global->nb_philo" pointers of type t_philo. Second malloc, 
   gives enough memory to contain all variables that can be found
   inside the t_philo struct and assign a value to each 
   of its variable. */

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
		global->philo[i]->status = EAT;
		global->philo[i]->id = (i + 1);
		global->philo[i]->time_last_meal = timestamp_in_ms();
		global->philo[i]->global = global;
		global->philo[i]->meal = 0;
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

/* This function initializes all the basic variables 
inside the t_global struct */
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
	if (global->time_must_eat == 0)
		error(ERR_DATA);
	if (global->nb_philo == 0)
		error(ERR_PHILO);
	global->meal_count = global->nb_philo * global->time_must_eat;
	global->status = EAT;
}

/*Function wraps up all functions that initialize the data:
  1- init_global_variables inits all variables that are not 
  pointers that are gound in t_global struct.
  2- init_global_forks inits the forks that are found 
  in t_global struct.
  3- init_each philo mallocs each philosophers (t_philo struct) and 
  the data it contains.*/

void	init_variables(t_global *global, char **argv)
{
	init_global_variables(global, argv);
	init_each_philo(global);
	philo_right_fork(global);
}

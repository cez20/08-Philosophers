/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:03:38 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/02 13:25:58 by cemenjiv         ###   ########.fr       */
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

int	init_each_philo(t_global *global)
{
	int	i;

	global->philo = malloc(global->nb_philo * sizeof(t_philo *));
	if (!global->philo)
		return (1);
	i = 0;
	while (i < global->nb_philo)
	{
		global->philo[i] = malloc(sizeof(t_philo));
		if (!global->philo[i])
			return (1);
		pthread_mutex_init(&global->philo[i]->fork, NULL);
		global->philo[i]->id = (i + 1);
		global->philo[i]->nb_meal = 0;
		global->philo[i]->status = EAT;
		global->philo[i]->time_last_meal = timestamp_in_ms();
		global->philo[i]->global = global;
		i++;
	}
	return (0);
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
			return (-1);
		i++;
	}
	nb = ft_atoi(argv);
	if (nb < 0)
		return (-1);
	return (nb);
}

/* This function initializes all the basic variables 
inside the t_global struct */
int	init_global_variables(t_global *g, char **argv)
{
	g->nb_philo = valid_int(argv[1]);
	g->time_to_die = valid_int(argv[2]);
	g->time_to_eat = valid_int(argv[3]);
	g->time_to_sleep = valid_int(argv[4]);
	if (g->nb_philo <= 0 || g->time_to_die < 0 || g->time_to_eat < 0 \
	|| g->time_to_sleep < 0)
		return (1);
	if (argv[5])
	{
		g->time_must_eat = valid_int(argv[5]);
		if (g->time_must_eat <= 0)
			return (1);
	}
	else
		g->time_must_eat = -1;
	g->meal_count = g->nb_philo * g->time_must_eat;
	g->status = EAT;
	pthread_mutex_init(&g->message, NULL);
	pthread_mutex_init(&g->fork_checker, NULL);
	return (0);
}

/*Function wraps up all functions that initialize the data:
  1- init_global_variables inits all variables that are not 
  pointers that are gound in t_global struct.
  2- init_global_forks inits the forks that are found 
  in t_global struct.
  3- init_each philo mallocs each philosophers (t_philo struct) and 
  the data it contains.*/

int	init_variables(t_global *global, char **argv)
{
	if (init_global_variables(global, argv))
		return (1);
	if (init_each_philo(global))
		return (1);
	philo_right_fork(global);
	return (0);
}

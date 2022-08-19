/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/18 17:16:09 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>   // for malloc 
# include <stdio.h>    // for perror 
# include <pthread.h>  // for all pthread functions
# include <sys/time.h> // for gettimeof day function 
# include <unistd.h> //for usleep function

#define ERR_ARGS "Error! Wrong number of arguments!\n"
#define	ERR_DATA "Error! The arguments are either negative numbers, float, letters or other!\n"
#define ERR_PHILO "Error! There are no philosophers to do the simulation\n"
#define FORK      "has taken a fork\n"
#define EAT       "is eating\n"
#define SLEEP     "is sleeping\n"
#define	THINK	  "is thinking\n"
#define	DIE       "died\n"
#define	DYING 0
#define EATING 1
#define	SLEEPING 2
#define THINKING 3


typedef struct s_philo	t_philo; // This allow to declare struct in s_data, because if not put here, it doesnt know what t_philo is

typedef struct s_data
{
	int 			nb_philo;
	int 			time_to_die; // argv[2]
	int 			time_to_eat; // argv[3]
	int 			time_to_sleep; // argv[4]
	int				time_must_eat; // argv[5]
	long long		timestamp_start;  //timestamp at the beginning of simulation
	t_philo			**philo;
	pthread_mutex_t message;
}			t_data;

typedef	struct s_philo
{
	pthread_t		thread;    	//Variable necessaire pour creer thread 
	pthread_mutex_t	fork;
	int				index;	// Number that will be assigned to this philosopher 
	int				id;
	int				nb_time_eat; // Numqber of time that philo eat. This number increase each time he eats.
	long long		time_last_meal; // Each philo has a different last meal time.
	int				status;
	t_philo			*next_thread;
	t_data			*data;
}			t_philo;


//*** 00_MAIN.C ***
int			main(int argc, char **argv);

//*** 01_INIT_DATA.C ***
int			valid_int(char *argv); 
void		init_data(t_data *data, char **argv);
void		malloc_philo(t_data *p);

//*** 02_INIT_SIMULATION.C ***
void		init_simulation(t_data *p);
void		*start(void *p);
void		philo_status(t_philo *p);
void		is_eating(t_philo *p);
void		is_thinking(t_philo * p);
void		print_message(t_philo *p, char *str);

//*** 03_END_SIMULATION.C ***
void    	end_simulation(t_data *p);

//*** 05_UTILS.C *** TO BE CHANGED FOR RIGHT NUMBER AT THE END 
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		error(char *str);
long long 	timestamp_in_ms();

//*** TEST.C ***
void		print_initial_data(t_data *p);

#endif

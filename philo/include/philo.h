/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/29 12:37:32 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>   // for malloc 
# include <stdio.h>    // for perror 
# include <pthread.h>  // for all pthread functions
# include <sys/time.h> // for gettimeof day function 
# include <unistd.h> //for usleep function

# define ERR_ARGS "Error! Wrong number of arguments!\n"
# define ERR_DATA "Error! Arguments are negative numbers, float, letters, etc\n"
# define ERR_PHILO "Error! There are no philosophers to do the simulation\n"
# define DIED 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DONE 4

typedef struct s_philo	t_philo;//allow to declare t_philo variable s_global

typedef struct s_global
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int 			all_philo_ate;
	int				status;
	long long		timestamp_start;
	pthread_mutex_t	message;
	pthread_mutex_t	all_ate;
	pthread_t		checker;
	t_philo			**philo;
}			t_global;

typedef struct s_philo
{
	int				status;
	int				id;
	//int				nb_time_ate;
	long long		time_last_meal;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	*right_fork;
	t_global		*global;
}			t_philo;

//*** 00_MAIN.C ***
int			main(int argc, char **argv);
void		*checker_loop(void *global);
void		is_dying(t_philo *p, char *str);

//*** 01_INIT_VARIABLES.C ***
void		init_variables(t_global *global, char **argv);
void		init_global_variables(t_global *global, char **argv);
int			valid_int(char *argv);
void		init_each_philo(t_global *global);
void		philo_right_fork(t_global *global);

//*** 02_INIT_MUTEX.C ***
void		init_mutex(t_global *global);
void		destroy_mutex(t_global *global);

//*** 02_START_SIMULATION.C ***
void		start_simulation(t_global *p);
void		*start(void *p);
void		is_eating(t_philo *p);
void		is_sleeping(t_philo *p);
void		is_thinking(t_philo *p);
void		print_message(t_philo *p, char *str);

//*** 03_END_SIMULATION.C ***
void		end_simulation(t_global *g);

//*** 05_UTILS.C *** TO BE CHANGED FOR RIGHT NUMBER AT THE END 
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		error(char *str);
long long	timestamp_in_ms(void);

//*** 06_UTILS1.C *** TO BE CHANGED FOR RIGHT NUMBER AT THE END
void		sequential_usleep(long long total_time_for_action, t_global *g);
void		free_struct(t_global *global);
void		print_message(t_philo *p, char *str);

//*** TEST.C ***
void		print_initial_values(t_global *p);

#endif

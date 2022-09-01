/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/01 17:20:15 by cemenjiv         ###   ########.fr       */
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
	long long		timestamp_start;
	int				meal_count;
	int				status;
	pthread_mutex_t	message;
	pthread_mutex_t	fork_checker;
	pthread_t		death_checker;
	t_philo			**philo;
}			t_global;

typedef struct s_philo
{
	int				status;
	int				id;
	long long		time_last_meal;
	int				meal;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	*right_fork;
	t_global		*global;
}			t_philo;

//*** 00_MAIN.C ***
int			main(int argc, char **argv);

//*** 01_INIT_VARIABLES.C ***
void		init_variables(t_global *global, char **argv);
void		init_global_variables(t_global *global, char **argv);
int			valid_int(char *argv);
void		init_each_philo(t_global *global);
void		philo_right_fork(t_global *global);

//*** 02_INIT_MUTEX.C ***
void		init_mutex(t_global *global);
void		destroy_mutex(t_global *global);

//*** 03_DEATH_CHECKER.C ***
void		is_dying(t_philo *p, char *str);
void		*check_if_dead(void *global);

//*** 04_START_PHILO_THREADS.C ***

void		is_thinking(t_philo *p);
void		is_sleeping(t_philo *p);
void		is_eating(t_philo *p);
void		*start(void *p);
void		start_philo_threads(t_global *p);

//*** 04_END_PHILO_THREADS.C ***
void		end_philo_threads(t_global *g);

//*** 05_LIBFT_UTILS.C *** 
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);

//*** 06_UTILS.C ***
void		free_struct(t_global *global);
void		sequential_usleep(long long total_time_for_action, t_global *g);
void		print_message(t_philo *p, char *str);
long long	timestamp_in_ms(void);
void		error(char *str);

#endif

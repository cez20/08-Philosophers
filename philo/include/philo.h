/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/02 14:47:10 by cemenjiv         ###   ########.fr       */
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
# define ERR_DATA "Error! Arguments are not valid integers for simulation!\n"
# define ERR_THREAD "Error! Problem while creating thread!\n"
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
	pthread_t		death_checker;
	pthread_mutex_t	message;
	//pthread_mutex_t	fork_checker;
	t_philo			**philo;
}			t_global;

typedef struct s_philo
{
	int				id;
	int				nb_meal;
	int				status;
	long long		time_last_meal;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	*right_fork;
	t_global		*global;
}			t_philo;

//*** 00_MAIN.C ***
int			main(int argc, char **argv);

//*** 01_INIT_VARIABLES.C ***
int			init_variables(t_global *global, char **argv);
int			init_global_variables(t_global *g, char **argv);
int			valid_int(char *argv);
int			init_each_philo(t_global *global);
void		philo_right_fork(t_global *global);

//*** 02_DEATH_CHECKER.C ***
void		*check_if_dead(void *global);

//*** 03_START_PHILO_THREADS.C ***

void		*start(void *p);
int			start_philo_threads(t_global *g);

//*** 04_PRINT_MESSAGE.C ***
void		is_dying(t_philo *p, char *str);
void		is_thinking(t_philo *p);
void		is_sleeping(t_philo *p);
void		is_eating(t_philo *p);
void		print_message(t_philo *p, char *str);

//*** 05_END_PHILO_THREADS.C ***
int			end_philo_threads(t_global *g);

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
int			error(char *str);

#endif

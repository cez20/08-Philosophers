/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/08 17:49:02 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>   // for malloc 
# include <stdio.h>    // for perror 
# include <pthread.h>  // for all pthread functions
# include <sys/time.h> // for gettimeof day function 
# include <unistd.h> //for usleep function

#define ERR_ARGS "Error! Wrong number of arguments"

struct    s_timeval 
{
	time_t        tv_sec ;   //used for seconds
	suseconds_t   tv_usec ;   //used for microseconds
}			t_timeval;

typedef struct s_thread
{
	pthread_t		*philo;
	pthread_mutex_t	mutex;
	int				*fork;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int				time_must_eat;
}				t_thread;

//*** MAIN.C ***
int		main(int argc, char **argv);
void	error(char *str);
long	get_time_ms(void);


//*** THREAD.C ***
void	*routine();
void	finish_thread(t_thread *thread);
void	create_thread(t_thread *thread);
void	create_data(t_thread *thread, char **argv);


//*** UTILS.C ***
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);



#endif
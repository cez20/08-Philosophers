/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/11 16:57:03 by cemenjiv         ###   ########.fr       */
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

typedef struct s_philo	t_philo; // This allow to declare struct in s_data, because if not put here, it doesnt know what t_philo is

typedef struct s_data
{
	int 		nb_philo;
	int 		time_to_die;
	int 		time_to_eat;
	int 		time_to_sleep;
	int			time_must_eat;
	long long	timestamp;
	t_philo		**philo;
}			t_data;

typedef	struct s_philo
{
	pthread_t		thread;    	//Variable necessaire pour creer thread 
	pthread_mutex_t	fork;	 // Lorsqu'on appelle pthread_mutex_lock(fork) on vient bloquer la fourchette.
	int				id;		// Number that will be assigned to this philosopher 
}			t_philo;


//*** 00_MAIN.C ***
int		main(int argc, char **argv);
void	error(char *str);

//*** 01_DATA.C ***
int		valid_int(char *argv);
void	init_data(t_data *data, char **argv);

//*** 02_THREAD.C ***
void	create_thread(t_data *p);


//*** UTILS.C ***		
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);


#endif



// typedef struct s_philo
// {
// 	pthread_t		*philo;
// 	pthread_mutex_t	mutex;
// 	int				*fork;
// 	int				nb_philo;
// 	int				time_to_die;
// 	int				time_to_eat;
// 	int 			time_to_sleep;
// 	int				time_must_eat;
// }				t_philo;
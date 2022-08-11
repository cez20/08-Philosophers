/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/08 18:11:55 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "philo.h"

//On peut compiler le programme en mettant les flags gcc -fsanitize=thread -g threads.c && ./a.out



// //Main function:
// Creates_data allows to put all argv into a variable of my struct (ex: gettimeofday,etc)
// Create_thread generates a loop that creates all thread for all philosophers
// finish_thread waits for each thread to finish 

int main(int argc, char **argv)
{
	t_thread	thread;
	long 		time_start;

	if (argc < 5 || argc > 6)
		error(ERR_ARGS);
	create_data(&thread, argv);
	create_thread(&thread);
	finish_thread(&thread);
	time_start = get_time_ms();
	return (0);
}

//tv_sec est le nombre de secondes ecoules depuis l'epoch
//tv_usec est le nombre de microsecondes ecoules depuis l'appel de la fonction gettimeoftheday

long	get_time_ms(void)
{
	struct timeval	tmp;
	long			ms;

	ms = 0;
	gettimeofday(&tmp, NULL);
	ms = tmp.tv_sec;
	printf("%ld\n", ms);
	//ms = tmp.tv_sec * 1000;  // Faire seconde * 1000 pour obtenir millisecondes 
	ms += tmp.tv_sec / 1000;
	return (ms);
}

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/11 15:20:36 by cemenjiv         ###   ########.fr       */
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
	t_data		data;
	//t_philo		philo;

	if (argc < 5 || argc > 6)
		error(ERR_ARGS);
	init_data(&data, argv);
	create_thread(&data);
	return (0);
}

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

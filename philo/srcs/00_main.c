/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/22 10:24:19 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "philo.h"

/*Main function:
Creates_data allows to put all argv into a variable of my struct (ex: gettimeofday,etc)
Create_thread generates a loop that creates all thread for all philosophers
finish_thread waits for each thread to finish */

int main(int argc, char **argv)
{
	t_global	global;

	if (argc < 5 || argc > 6)
		error(ERR_ARGS);
	init_variables(&global, argv);
	init_mutex(&global);
	start_simulation(&global);
	end_simulation(&global);
	destroy_mutex(&global);
	free_struct(&global);
	return (0);
}

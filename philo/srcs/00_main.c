/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/24 16:27:26 by cemenjiv         ###   ########.fr       */
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
	if (pthread_create(&global.checker, NULL, checker_loop, &global) != 0)
		return 1;
	pthread_detach(global.checker);
	start_simulation(&global);
	end_simulation(&global);
	destroy_mutex(&global);
	free_struct(&global);
	return (0);
}

void	*checker_loop(void *global)
{
	t_global	*g;
	long long	current_timestamp;
	int 		i;

	g = (t_global *)global;
	while (g->status != DIED)
	{
		i = 0;
		while (i < g->nb_philo)
		{
			current_timestamp = timestamp_in_ms();
			if ((current_timestamp - g->philo[i]->time_last_meal) > g->time_to_die)
			{
				print_message(g->philo[i], "died\n");
				g->status = DIED;
				//usleep(100); // Laissse suffisament a un thread en cours de terminer
			}
			if (g->status == DIED) // Loop pour breaker rapidement. 
				break;
			i++;
		}	
	}
	return (NULL);
}
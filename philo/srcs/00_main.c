/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/29 13:04:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Main function:
Creates_data allows to put all argv into a variable of my struct 
(ex: gettimeofday,etc).Create_thread generates a loop that creates 
all thread for all philosophers finish_thread waits for each thread 
to finish */
int	main(int argc, char **argv)
{
	t_global	global;

	if (argc < 5 || argc > 6)
		error(ERR_ARGS);
	init_variables(&global, argv);
	init_mutex(&global);
	if (pthread_create(&global.checker, NULL, checker_loop, &global) != 0)
		return (1);
	//pthread_detach(global.checker); // Detach afin que programme n'attende jamais que cette loop termine. 
	start_simulation(&global);
	end_simulation(&global);
	destroy_mutex(&global);
	free_struct(&global);
	return (0);
}

/* Regarder si le usleep(100) est vraiment necessaire  */
void	*checker_loop(void *global)
{
	t_global	*g;
	long long	current_time;
	int			i;

	g = (t_global *)global;
	//while (g->status != DIED && g->all_philo_ate != 0) // Ajouter la 2eme condition ici
	while (g->status != DIED && g->status != DONE) // Ajouter la 2eme condition ici
	{
		i = 0;
		while (i < g->nb_philo)
		{
			current_time = timestamp_in_ms();
			if ((current_time - g->philo[i]->time_last_meal) > g->time_to_die)
			{
				g->status = DIED;
				is_dying(g->philo[i], "died\n");
				usleep(100);
			}
			if (g->status == DIED)
				break ;
			i++;
		}
		//if (g->all_philo_ate == 0) // J'ai ajoute cette condition afin qu'il sorte de la loop. 
			//break; // j'ai ajoute cette condition. 
	}
	return (NULL);
}

void	is_dying(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->global->message);
	printf("%lld ", timestamp_in_ms() - p->global->timestamp_start);
	printf("%d ", p->id);
	printf("%s", str);
	pthread_mutex_unlock(&p->global->message);
}

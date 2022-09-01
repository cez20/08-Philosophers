/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/31 23:24:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc < 5 || argc > 6)
		error(ERR_ARGS);
	init_variables(&global, argv);
	init_mutex(&global);
	if (pthread_create(&global.death_checker, NULL, check_if_dead, &global))
		return (1);
	pthread_detach(global.death_checker);
	start_philo_threads(&global);
	end_philo_threads(&global);
	destroy_mutex(&global);
	free_struct(&global);
	return (0);
}

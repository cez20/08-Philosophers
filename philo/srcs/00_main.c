/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/01 18:13:40 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc < 5 || argc > 6)
		return (error(ERR_ARGS));
	if (init_variables(&global, argv))
		return (1);
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

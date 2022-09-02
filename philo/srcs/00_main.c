/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/02 01:05:25 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc < 5 || argc > 6)
		return (error(ERR_ARGS));
	if (init_variables(&global, argv))
		return (2);
	if (init_mutex(&global))
		return (3);
	if (pthread_create(&global.death_checker, NULL, check_if_dead, &global))
		return (4);
	pthread_detach(global.death_checker);
	if (start_philo_threads(&global))
		return (5);
	if (end_philo_threads(&global))
		return (5);
	if (destroy_mutex(&global))
		return (3);
	free_struct(&global);
	return (0);
}

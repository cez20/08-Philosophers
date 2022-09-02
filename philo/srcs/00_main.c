/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/09/02 13:12:51 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc < 5 || argc > 6)
		return (error(ERR_ARGS));
	if (init_variables(&global, argv))
		return (error(ERR_DATA));
	if (pthread_create(&global.death_checker, NULL, check_if_dead, &global))
		return (error(ERR_THREAD));
	if (start_philo_threads(&global))
		return (error(ERR_THREAD));
	if (end_philo_threads(&global))
		return (error(ERR_THREAD));
	return (0);
}

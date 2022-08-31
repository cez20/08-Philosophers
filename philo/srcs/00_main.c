/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/30 21:11:42 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Init_variables, init all elements in the structures
Init mutex initiates all mutex for fork, message, and all_ate
start_simulation creates all thread necessary for program
end_simulation calls pthread_join(wait), to end all thread created
destroy_mutex destroys all mutex that have been initialized
free struct frees all elements that have been malloc*/

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc < 5 || argc > 6)
		error(ERR_ARGS);
	init_variables(&global, argv);
	init_mutex(&global);
	if (pthread_create(&global.death_checker, NULL, check_if_dead, &global))
		return (1);
	start_simulation(&global);
	end_simulation(&global);
	destroy_mutex(&global);
	free_struct(&global);
	return (0);
}

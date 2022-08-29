/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_end_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:38:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/29 12:50:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_global *g)
{
	int	i;

	i = 0;
	while (i < g->nb_philo)
	{
		pthread_join(g->philo[i]->thread, NULL);
		i++;
	}
	pthread_join(g->checker, NULL); // Ajouter cette condition ici 
}

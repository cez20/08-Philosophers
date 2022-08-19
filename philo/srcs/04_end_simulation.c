/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_end_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:38:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/18 12:39:16 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    end_simulation(t_data *p)
{
    int i;
    
    i = 0;
    while (i < p->nb_philo) // Loop pour attendre chacun des threads.
    {
        pthread_join(p->philo[i]->thread, NULL);
        i++;
    }
}
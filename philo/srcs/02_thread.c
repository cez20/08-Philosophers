/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/11 17:06:43 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

/* This function takes the double pointer **philo inside my data struct. This double_pointer points
to another structure that contains all the information regarding each philosophers. We malloc enough memory to
the double pointers so that it can accept all philo struct. Then, after we malloc each subelements so that it has enough
memory */

void	create_thread(t_data *p)
{
	int i;

	i = 0;
	p->philo = malloc(p->nb_philo * sizeof(t_philo *)); //verifier que le sizeof est bon. 
	if (!p->philo)
		return ;
	while (i < p->nb_philo)
	{	
		p->philo[i] = malloc(sizeof(t_philo)); // Verifier que le sizeof est bon
		p->philo[i]->id = i + 1;
		i++;
	}
	printf("%d\n", p->philo[0]->id);
	printf("%d\n", p->philo[1]->id);
	printf("%d\n", p->philo[2]->id);
	printf("%d\n", p->philo[3]->id);
}
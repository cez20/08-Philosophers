/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:59:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/11 16:44:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

/* This function will create a pointer to philo
*/
void	create_thread(t_data *p)
{
	int i;

	i = 0;
	p->philo = malloc(p->nb_philo * sizeof(t_philo)); // Malloc le double pointeur
	if (!p->philo)
		return ;
	p->philo[i] = malloc(sizeof(t_philo)); //malloc chacune des cases pour avoir la struct 
	p->philo[i]->str = malloc (15 * sizeof(char));
	p->philo[i]->str = "Cesar Menjivar";
	printf("%s\n", p->philo[i]->str);
	p->philo[i]->id = 36;
	printf("%d\n", p->philo[i]->id); 
}
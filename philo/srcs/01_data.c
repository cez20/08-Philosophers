/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:03:38 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/11 15:05:23 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_int(char *argv)
{
	int i;
	int nb;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) != 1)
			error(ERR_DATA);
		i++;
	}
	nb = ft_atoi(argv);
	if (nb < 0)
		error(ERR_DATA);	
	return (nb);
}

void	init_data(t_data *data, char **argv)
{
	data->nb_philo = valid_int(argv[1]);
	data->time_to_die = valid_int(argv[2]);
	data->time_to_eat = valid_int(argv[3]);
	data->time_to_sleep = valid_int(argv[4]);
	if (argv[5])
		data->time_must_eat = valid_int(argv[5]);
	else
		data->time_must_eat = 0;
	if (data->nb_philo == 0)
		error(ERR_PHILO);
}
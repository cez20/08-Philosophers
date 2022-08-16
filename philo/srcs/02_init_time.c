/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:17:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/16 17:25:17 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_time(t_data *data)
{
	long long	timestamp_start;

	timestamp_start = get_time_in_ms();
	data->timestamp = get_time_in_ms() - timestamp_start;
	usleep(100); // Pourquoi mettre cela ??
	//printf("%d\n", data->timestamp); // imprime la difference de temps en ms. 
}

long long get_time_in_ms()
{
	struct timeval		time;
	long long			timestamp;

	gettimeofday(&time, NULL);
	timestamp = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (timestamp);
}


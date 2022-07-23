/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:29:46 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:30:06 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_global	*global;
	int			flag;

	flag = 0;
	if (argc < 5 || argc > 6)
		return (put_error(flag));
	flag = init_global(&global, argv);
	if (flag)
		return (free_philo(global, flag));
	pthread_create(&(global->thread_id), NULL, start_time, global);
	pthread_detach(global->thread_id);
	start_philo(global);
	loop_healt(global);
	flag = wait_philo(global);
	return (free_philo(global, flag));
}

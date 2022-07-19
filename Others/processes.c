/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:08:25 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/07/19 14:24:49 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

//Processes can contain multiple threads inside a single process. 

int main(int argc, char **argv)
{
	int x = 2;
	int pid = fork();
	if(pid == -1)
		return 1;
	if (pid == 0)
		x++;
	sleep(2);
	printf("%d\n", x);
	if (pid != 0)
	{
		wait(NULL);
	}
	return 0;	
}
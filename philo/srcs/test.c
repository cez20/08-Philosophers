/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:58:24 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/18 17:12:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* The list of all functions that can be found here are essentially to test
the whole program during its execution. A small description under each section 
will be found. */ 

//On peut compiler le programme en mettant les flags gcc -fsanitize=thread -g threads.c && ./a.out


//This function prints the initial data at the beginning of program 
// void	print_initial_data(t_data *p)
// {
// 	int i;

// 	printf("There are [%d] philosophers in total for this program\n", p->nb_philo);
// 	printf("The time_to die in millisecond is [%d] for this program\n", p->time_to_die);
// 	printf("The time_to eat in millisecond is [%d] for this program\n", p->time_to_eat);
// 	printf("The time_to sleep in millisecond is [%d] for this program\n", p->time_to_sleep);
	
// 	i = 0;
// 	while (i < p->nb_philo)
// 	{
// 		printf("The index %d philosopher id is [%d].\n", i, p->philo[i]->id);
// 		printf("The philosopher has eaten [%d] times.\n", p->philo[i]->nb_time_eat);
// 		printf("The philosophers last meal is at [%d] (in milliseconds) from start.\n", p->philo[i]->time_last_meal);
// 		i++;		
// 	}
// }


// Chaque fourchette est un mutex. Donc, lorsque 
// 	- je call mutex_lock(fouchette) ce qui bloque la fourchette du thread actuel 
// 	- Pour manger, j'ai besoin d'une autre fourchette:
// 		- Je bloque aussi la fourchette d'un autre philosophe
// 	- Une fois les 2 fourchettes en main, je mange pour le temps indique par time_to_eat
// 	- Une fois termine, je unlock la fourchette de mon philosophe d'a cote (devient dispo);
// 	- je unlock ma fourchette (car un autre philosophe en aura besoin);
// 	- Je dors pour le temps indique et affiche le nessage "X is sleeping";
// 	- Je "think", le temps pour  THINK n'est pas precise. On peut mettre ce qu'on veut je crois.
// 	- On repete les etapes en boucle (eat, sleep, think en loop). Sinon, DIE. 

// Faire les tests suivants:
// - Caller les fourchettes sans prendre un mutex.
// - Tous les philosophes impairs devront partir usleep second(usleep(1000)) apres les philosophes pairs.
//   De cette facon, la fourchette a droite est "TOUJOURS" disponible. 
// - Si un philosophe prend une fourchette et que la 2e n'est pas disponible, il doit deposer la sienne?
// - time_to_die. "Si chaque philosophe n'a pas commence a mange time_to_die milliseconds apres le debut de la simulatin
// ou depuis son dernier repas.", il meurt et affiche "philosopher is dead"
// - Est-ce que je peux mettre un mutex_init, mutex_lock a l'interieur d'un autre mutex lock?


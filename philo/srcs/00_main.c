/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/17 08:13:04 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "philo.h"

/*Main function:
Creates_data allows to put all argv into a variable of my struct (ex: gettimeofday,etc)
Create_thread generates a loop that creates all thread for all philosophers
finish_thread waits for each thread to finish */

int main(int argc, char **argv)
{
	t_data		data;

	if (argc < 5 || argc > 6)
		error(ERR_ARGS);
	init_data(&data, argv);
	init_time(&data);
	init_simulation(&data);
	return (0);
}



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



// Autres:
// - "Tout message affiche ne doit pas etre melange avec un autre message" ????

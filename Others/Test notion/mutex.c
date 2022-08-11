/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:45:41 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/10 14:56:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


typedef	struct s_mutex
{
	pthread_mutex_t	mutex;
	int	count;
} 			t_mutex;


void	*routine(void *data)
{
	t_mutex		*mutex; 
	pthread_t 	id;
	int			i;

	// Print number of current thread.
	id = pthread_self(); 
	printf("Thread [%ld] is inside the function\n", id);

	// Start the mutex lock here 
	mutex = (t_mutex *)data; // Typecast void *data to become a t_mutex*
	pthread_mutex_lock(&mutex->mutex);
	i = 0;
	while (i < 21000)
	{
		mutex->count++;
		i++;
	}
	pthread_mutex_unlock(&mutex->mutex);
	return (NULL);
}

int main ()
{
	pthread_t	t1; // pthread_t variable for pthread_create 
	pthread_t   t2; // pthread_t variable for pthread_create
	t_mutex		mutex; // Declare variable mutex of type struct t_mutex 
	
	// Initalize the mutex for protection
	pthread_mutex_init(&mutex.mutex, NULL);
	mutex.count = 0; 
	
	// Creation of 1st thread
	pthread_create(&t1, NULL, &routine, (void *)&mutex); 
	printf("Main: Creation of first thread [%ld]\n", t1);

	// Creation of 2nd thread 
	pthread_create(&t2, NULL, &routine, (void *)&mutex); //t_mutex struct is passed as arg here
	printf("Main: Creation of second thread [%ld]\n", t2);

	 // First thread is "joined"
	pthread_join(t1, NULL);
	printf("First thread is returned to system\n");
	
	// Second thread is "joined"
	pthread_join(t2, NULL); // Completion of second thread
	printf("Second thread is returned to system\n");
	
	//Prints out final result and destroy mutex 
	printf("The final count is: %d\n", mutex.count);
	pthread_mutex_destroy(&mutex.mutex);
	
	return (0);
}
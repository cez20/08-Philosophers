/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:54:34 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/08/10 14:44:22 by cemenjiv         ###   ########.fr       */
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
} t_mutex;


void	*routine(void *data)
{
	t_mutex		*mutex; // Declares
	pthread_t 	id;
	int			i;

	// Print number of current thread.
	id = pthread_self(); 
	printf("Thread [%ld] is inside the function\n", id);

	// Tak
	mutex = (t_mutex *)data;
	
	//pthread_mutex_lock(&mutex->mutex);
	i = 0;
	while (i < 21000)
	{
		mutex->count++;
		i++;
	}
	//pthread_mutex_unlock(&mutex->mutex);
	return (NULL);
}

int main ()
{
	pthread_t	t1; // pthread_t variable for pthread_create 
	pthread_t   t2; // pthread_t variable for pthread_create
	t_mutex		mutex; // Declare variable mutex of type struct t_mutex 
	
	// Initalize the mutex for protection
	//pthread_mutex_init(&mutex.mutex, NULL);
	mutex.count = 0; 
	// Creation of 1st thread
	pthread_create(&t1, NULL, &routine, (void *)&mutex); 
	printf("Main: Creation of first thread [%ld]\n", t1);

	// Creation of 2nd thread 
	pthread_create(&t2, NULL, &routine, (void *)&mutex); // Creation of 2ndthread
	printf("Main: Creation of second thread [%ld]\n", t2);

	 // First thread is "joined"
	pthread_join(t1, NULL);
	printf("First thread is returned to system\n");
	
	// Second thread is "joined"
	pthread_join(t2, NULL); // Completion of second thread
	printf("Second thread is returned to system\n");
	
	//Prints out final result and destroy mutex 
	printf("%d\n", mutex.count);
	//pthread_mutex_destroy(&mutex.mutex);
	
	return (0);
}

// int main ()
// {
// 	pthread_t	t1; // Creating a pthread_t variable necessary to create thread
// 	pthread_t   t2; // Creating another pthread_t variable

// 	pthread_create(&t1, NULL, &routine, NULL);  // Creation of 1st thread
// 	printf("Main: Creation of first thread [%ld]\n", t1);
// 	pthread_create(&t2, NULL, &routine, NULL); // Creation of 2ndthread
// 	printf("Main: Creation of second thread [%ld]\n", t2);
// 	
// 	return (0);
// }

/* This function show how to calculate the time elapsed since epoch by addiing the number 
of seconds to the number of microsecond. Both data have been changed to milliseconds
tv.sec * 1000 (to change seconds to milliseconds) and tv.usec / 1000 to change micro to milli */

// int main()
// {
// 	struct timeval time;
// 	gettimeofday(&time, NULL);
// 	printf("The number of seconds in milliseconds is: %ld\n", time.tv_sec * 1000);
// 	printf("The number of microseconds in milliseconds is: %d\n", time.tv_usec / 1000);
// 	printf("To calculate the time in millisecondes we do the second * 1000 and the microsecond / 1000 which gives : %ld\n", (time.tv_sec * 1000) + (time.tv_usec / 1000));
// 	//sleep(5);
// }


/* The following function shows the number of milliseconds it takes in order to calculate
   the execution of a program*/

// int main ()
// {
// 	struct timeval	start; //Create a struct named 'start' of type timeval which contains start.sec (seconds) and start.usec (microseconds)
// 	struct timeval	end; // Create a struct named 'end' of type timeval which contains end.sec(seconds) and end.used(microseconds)

// 	gettimeofday(&start, NULL);
// 	for (int i = 0; i <1e5 ; i++) { // This line iterates 100 000 times
// 	}
//   	gettimeofday(&end, NULL);

// 	// This is to calculate the execution time of program in microseconds
//   	printf("Time taken to count to 10^5 is : %ld microseconds\n",
//     ((end.tv_sec * 1000000 + end.tv_usec) -
//     (start.tv_sec * 1000000 + start.tv_usec)));
	
// 	//This is to calculate the execution time of program in milliseconds
// 	printf("Time taken to count to 10^5 is : %ld milliseconds\n",
//     ((end.tv_sec * 1000 + end.tv_usec / 1000) -
//     (start.tv_sec * 1000 + start.tv_usec / 1000)));

// 	//This is to calculate the execution time of program in seconds
// 	printf("Time taken to count to 10^5 is : %ld seconds\n",
//     ((end.tv_sec + end.tv_usec / 1000000) -
//     (start.tv_sec + start.tv_usec / 1000000)));

//   	return 0;
// }

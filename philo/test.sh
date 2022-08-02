#!/bin/bash

make re
make clean

# ------------------------------------ERRORS----------------------------------- 

printf "\033[1;32m----------------------------ERROR TEST WHEN NOT THE RIGHT NUMBERS OF PARAMETERS ----------------------------\n\n\n\033[1;0m"

printf "\033[1;33m-------------- ERROR TEST WHEN NOT ARGC is 1 --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo \n\033[1;0m"
./philo

printf "\033[1;33m-------------- ERROR TEST WHEN NOT ARGC is 2 --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 \n\033[1;0m"
./philo 4

printf "\033[1;33m-------------- ERROR TEST WHEN NOT ARGC is 3 --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 1000\n\033[1;0m"
./philo 4 1000

printf "\033[1;33m-------------- ERROR TEST WHEN NOT ARGC is 4 --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 1000 500 \n\033[1;0m"
./philo 4 1000 500

printf "\033[1;33m-------------- ERROR TEST WHEN NOT ARGC is 7 --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 1000 500 500 400 400 \n\033[1;0m"
./philo 4 1000 500 500 400 400


# ------------------------------------PROGRAM RUNNING CORRECTLY----------------------------------- 

printf "\n\033[1;32m----------------------------WHEN PROGRAM RUNS SMOOTHLY ----------------------------\n\n\n\033[1;0m"

printf "\033[1;33m-------------- PROGRAM RUNNING CORRECTLY WITH ARGC=5--------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE OK--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 1000 500 500 400 \n\033[1;0m"
./philo 4 1000 500 500

printf "\033[1;33m-------------- PROGRAM RUNNING CORRECTLY WITH ARGC=6--------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE OK--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 1000 500 500 400 \n\033[1;0m"
./philo 4 1000 500 500 400

#Premier test: S'assurer que tous les threads sont crees en meme temps et qu'apres il se ferme
#Valider la boucle while de pthread_create, tous les philosophers doivent etre cree
#valider que pthread_join wait pour tous les threads. 

make fclean


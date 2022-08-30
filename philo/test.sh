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


printf "\033[1;32m----------------------------ERROR TEST WHEN PARAMETERS NOT VALID ----------------------------\n\n\n\033[1;0m"

printf "\033[1;33m-------------- ERROR TEST WHEN ARGV IS A NEGATIVE NUMBER --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 -2147483648 1000 1000 \n\033[1;0m"
./philo 4 -2147483648 1000 1000

printf "\033[1;33m-------------- ERROR TEST WHEN ARGV IS A FLOAT NUMBER --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 0.5 1000 1000 \n\033[1;0m"
./philo 4 0.5 1000 1000

printf "\033[1;33m-------------- ERROR TEST WHEN ARGV IS A NEGATIVE FLOAT NUMBER --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 -127.35 1000 1000 \n\033[1;0m"
./philo 4 -127.35 1000 1000

printf "\033[1;33m-------------- ERROR TEST WHEN ARGV IS BEYOND INT_MAX --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 2147483648 1000 1000 \n\033[1;0m"
./philo 4 2147483648 1000 1000

printf "\033[1;33m-------------- ERROR TEST WHEN ARGV IS A LETTER --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 A 1000 1000 \n\033[1;0m"
./philo 4 A 1000 1000

printf "\033[1;33m-------------- ERROR TEST WHEN ARGV IS A SYMBOL --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 @ 1000 1000 \n\033[1;0m"
./philo 4 @ 1000 1000

printf "\033[1;33m-------------- ERROR TEST WHEN ARGV[1] (NB_OF_PHILO) IS ZERO() --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 0 500 1000 1000 \n\033[1;0m"
./philo 0 500 1000 1000

# ------------------------------------PROGRAM RUNNING BUT ENDING BECAUSE DEATH OR FINISH MEAL----------------------------------- 

printf "\033[1;33m-------------- PROGRAM RUNS WITH 1 PHILOSOPHER --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD TAKE A FORK AND THEN DIES --------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 1 800 200 200 \n\033[1;0m"
./philo 1 800 200 200

printf "\033[1;33m-------------- PROGRAM RUNS WITH 1 PHILOSOPHER --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD TAKE A FORK AND THEN DIES --------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 5 800 200 200 7 \n\033[1;0m"
./philo 5 800 200 200 7



# ------------------------------------PROGRAM RUNNING CORRECTLY----------------------------------- 

# printf "\n\033[1;32m----------------------------WHEN PROGRAM RUNS SMOOTHLY ----------------------------\n\n\n\033[1;0m"

# printf "\033[1;33m-------------- PROGRAM RUNNING CORRECTLY WITH ARGC=5--------------\n\033[1;0m"
# printf "\033[1;31m--------------PROGRAM SHOULD RUN AND PHILO DIES--------------\n\033[1;33m"
# printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 1000 500 500 \n\033[1;0m"
# ./philo 4 1000 500 500

# printf "\033[1;33m-------------- PROGRAM RUNNING CORRECTLY WITH ARGC=6--------------\n\033[1;0m"
# printf "\033[1;31m--------------SHOULD STOP AFTER EATING 6 TIMES--------------\n\033[1;33m"
# printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 1000 500 500 400 \n\033[1;0m"
# ./philo 4 1000 500 500 6

# printf "\033[1;33m-------------- PROGRAM RUNNING CORRECTLY WITH 1 PHILOSOPHER--------------\n\033[1;0m"
# printf "\033[1;31m--------------PHILO SHOULD TAKE A FORK AND DIE --------------\n\033[1;33m"
# printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 4 1000 500 500  \n\033[1;0m"
# ./philo 1 1000 500 500

# printf "\033[1;33m-------------- PROGRAM RUNNING CORRECTLY WITH 5 PHILOSOPHERS--------------\n\033[1;0m"
# printf "\033[1;31m--------------PHILOS SHOULD EAT INDEFINITELY --------------\n\033[1;33m"
# printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 5 800 200 200  \n\033[1;0m"
# ./philo 5 800 200 200

# printf "\033[1;33m-------------- PROGRAM RUNNING CORRECTLY WITH 5 PHILOSOPHERS--------------\n\033[1;0m"
# printf "\033[1;31m--------------PHILO SHOULD EAT 7 times and stop stimulation--------------\n\033[1;33m"
# printf "\033[1;34mSCRIPT TEST IS DONE WITH ./philo 5 800 200 200 7  \n\033[1;0m"
# ./philo 5 800 200 200 7


sleep 10

make fclean


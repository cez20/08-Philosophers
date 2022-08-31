# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:53:41 by cemenjiv          #+#    #+#              #
#    Updated: 2022/08/31 12:44:30 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo 

SRCS			= $(wildcard srcs/*.c)

OBJS_DIR		= objs/

HEADER			= -Iinclude/
				  	  
HEADER_PATH     = include/

PTHREAD			= -pthread
						
OBJS			= $(SRCS:.c=.o) #Declaration OBJS (objets). Tous les fichiers terminant par le suffixe .c vont devenir .o

CC				= gcc  #name of C compiler
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f  #shortcut Rm fait ce que fait normalement rm -f 

%.o: %.c
				$(CC) $(CFLAGS) $(HEADER) $(LPTHREAD) -c $< -o $@

all:			$(NAME)  #commande "make all" fait ce que la variable NAME fait

$(NAME):		$(OBJS)
				@printf "\033c"
				@echo "\n\033[33m    COMPILING [*......]"
				@sleep 0.5
				@printf "\033c"
				@echo "\n\033[33m    COMPILING [****...]"
				@$(CC) ${OBJS} -o $@
				@sleep 0.5
				@printf "\033c"
				@echo "\n\033[33m    COMPILING [*******]"
				@echo "\n\033[32m\033[1m philo program is compiled! \n\033[0m"					
	
clean:		
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all
				
.PHONY:			all clean fclean re norm warning

norm:
				@norminette $(HEADER_PATH)
				@norminette $(SRCS)
				
warning:		CFLAGS += -w
warning:		$(NAME)

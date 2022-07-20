# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:53:41 by cemenjiv          #+#    #+#              #
#    Updated: 2022/07/20 17:00:43 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = $(not dir $(wilcard /srcs/*.c))
OBJS = $(SRCS:.c=.o)

INC = -Iinclude/

CC     = gcc
CFLAGS = -Wall -Wextra -Werror -g 
RM     = rm -f

.c.o:		
			${CC} ${CFLAGS} ${INC} -c $< -o $(<:.c=.o)

all:      	$(NAME)


$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:     
			$(RM) $(OBJS) 

fclean:     clean
			$(RM) $(NAME)
 
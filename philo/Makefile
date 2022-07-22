# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:53:41 by cemenjiv          #+#    #+#              #
#    Updated: 2022/07/22 12:57:05 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS:= $(notdir $(wildcard srcs/*.c))
OBJS:= $(SRCS:.c=.o) #Is this really mandatory???

INC = -Iinclude/

CC     = gcc
CFLAGS = -Wall -Wextra -Werror -g 
RM     = rm -f


## This is called a double suffix rule. It is defined by a a pair of suffixes: target suffi and the source suffix
# target suffix is .o and sources suffix are .c
#.c.o is equivalent to the pattern rule %.o : %.c

%.o: %.c 
	$(CC) $(CFLAGS) -c $<

all:    $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)
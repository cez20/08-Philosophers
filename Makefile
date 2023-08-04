# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:53:41 by cemenjiv          #+#    #+#              #
#    Updated: 2023/08/03 21:39:27 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

SRCS_DIR		= srcs/
OBJS_DIR		= objs/

HEADER_DIR      = include/

PTHREAD			= -pthread

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

SRCS			= srcs/main.c srcs/init_variables.c srcs/start_global_death_checker.c \
				  srcs/start_philo_threads.c srcs/print_messages.c srcs/end_philo_threads.c \
				  srcs/libft_utils.c srcs/utils.c 
				  
OBJS			= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -I$(HEADER_DIR) $(PTHREAD) -c $< -o $@

all:			objs $(NAME)

$(NAME):		$(OBJS)
				@$(CC) ${OBJS} -o $@
				
clean:
				$(RM) $(OBJS)
				$(RM) -rf $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re norm warning

objs:
				mkdir -p objs

norm:
				@norminette $(HEADER_DIR)
				@norminette $(SRCS)

warning:		CFLAGS += -w
warning:		$(NAME)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 17:41:51 by karocha-          #+#    #+#              #
#    Updated: 2024/11/03 18:16:01 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= cc
CFLAGS			= -g -Wall -Wextra -Werror
RM				= rm -rf

MAIN			= main.c parser.c

MOVES_DIR		= ./moves/push.c ./moves/rotate.c ./moves/rrotate.c \
./moves/swap.c

ALGORITHM_DIR	= ./algorithm/algorithm.c ./algorithm/sorts.c \


HELPER_FUNC_DIR	= ./helper_func/helpers.c ./helper_func/helpers2.c \
./helper_func/ft_atol.c ./helper_func/ft_lstadd_back.c \
./helper_func/ft_lstadd_front.c ./helper_func/ft_lstdelone.c \
./helper_func/ft_lstiter.c ./helper_func/ft_lstlast.c ./helper_func/ft_lstnew.c \
./helper_func/ft_lstsize.c\

SRCS			= $(MAIN) $(MOVES_DIR) $(ALGORITHM_DIR) \
$(HELPER_FUNC_DIR)

LIBFT_DIR		= ./libft/libft.a
LIBFT_PATH		= ./libft
LIBFT_HEADER	= ./libft/libft.h


OBJS = $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)  $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR) -o $(NAME)

$(LIBFT_DIR): 
			make -C$(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		make -C$(LIBFT_PATH) clean
		$(RM) $(OBJS)

fclean: clean
		make -C$(LIBFT_PATH) fclean
		$(RM) $(NAME)
		

re: fclean all

.PHONY: all clean fclean re
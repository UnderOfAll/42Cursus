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
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -rf

MAIN			= main.c parser.c

MOVES_DIR		= ./moves/push.c ./moves/rotate.c ./moves/rrotate.c \
./moves/swap.c

ALGORITHM_DIR	= ./algorithm/algorithm.c ./algorithm/sorts.c ./algorithm/helpers.c \
./algorithm/helpers2.c


LIBFT_DIR 		= ./libft/ft_atol.c ./libft/ft_bzero.c ./libft/ft_calloc.c \
./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstlast.c \
./libft/ft_lstnew.c ./libft/ft_lstsize.c ./libft/ft_putstr_fd.c

SRCS			= $(MAIN) $(MOVES_DIR) $(ALGORITHM_DIR) \
$(LIBFT_DIR)

LIBFT_DIR		= ./libft/libft.a
LIBFT_PATH		= ./libft


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
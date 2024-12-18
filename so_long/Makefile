# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:53:04 by karocha-          #+#    #+#              #
#    Updated: 2024/12/13 19:55:36 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror
RM		= rm -rf

LIBFT_DIR		= ./libft/libft.a
LIBFT_PATH		= ./libft
LIBFT_HEADER	= ./libft/libft.h

SRCS = main.c 

OBJS = $(SRCS:.c=.o)

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
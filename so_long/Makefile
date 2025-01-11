# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:53:04 by karocha-          #+#    #+#              #
#    Updated: 2025/01/11 18:05:39 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror
RM		= rm -rf

LIBFT_DIR		= ./libraries/libft/libft.a
LIBFT_PATH		= ./libraries/libft
LIBFT_HEADER	= ./libraries/libft/libft.h

SRCS = main.c ./parse_map/helpers.c ./parse_map/map_check.c ./parse_map/exit.c

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
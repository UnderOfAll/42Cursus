# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:53:04 by karocha-          #+#    #+#              #
#    Updated: 2025/01/14 20:51:13 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror
RM		= rm -rf

LIBFT_DIR		= ./libraries/libft/libft.a
LIBFT_PATH		= ./libraries/libft
LIBFT_HEADER	= ./libraries/libft/libft.h

SRCS = main.c ./parse_map/helpers.c ./parse_map/map_check.c ./parse_map/exit.c \
./parse_map/map_utils.c ./parse_map/flood_fill.c 

OBJS = $(SRCS:.c=.o)

$(NAME):		$(OBJS)  $(LIBFT_DIR)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR) -o $(NAME)

$(LIBFT_DIR): 
			@make -sC $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@make -sC $(LIBFT_PATH) clean
		@$(RM) $(OBJS)

fclean: clean
		@make -sC $(LIBFT_PATH) fclean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
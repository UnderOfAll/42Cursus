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
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
SRCS			= main.c parse.c ./libft/ft_atol.c ./libft/ft_bzero.c \
./libft/ft_calloc.c ./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c \
./libft/ft_lstlast.c ./libft/ft_lstnew.c ./libft/ft_lstsize.c \
./libft/ft_putstrfd.c \

LIBFT_SRC		= ./libft/libft.a
LIBFT_PATH		= ./libft

OBJS = $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_SRC)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libftclean:
		make -C$(LIBFT_PATH) clean

libftfclean:
		make -C$(LIBFT_PATH) fclean

clean:libftclean
		$(RM) $(OBJS)

fclean: clean libftclean
		$(RM) $(NAME) $(NAME).a

re: fclean all

.PHONY: all clean fclean re
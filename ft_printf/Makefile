# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 16:42:00 by karocha-          #+#    #+#              #
#    Updated: 2024/06/18 17:12:10 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
SRCS 			= ft_printf.c ft_numbase_signed.c ft_numbase_unsigned.c

OBJS = $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

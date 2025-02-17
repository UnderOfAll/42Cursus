# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 19:17:57 by karocha-          #+#    #+#              #
#    Updated: 2024/12/19 19:19:41 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atol.c ft_bzero.c ft_calloc.c ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_putstr_fd.c

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
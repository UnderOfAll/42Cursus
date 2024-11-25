# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:16:09 by karocha-          #+#    #+#              #
#    Updated: 2024/06/03 17:39:05 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c ft_isalpha.c ft_bzero.c  ft_isascii.c \
					ft_calloc.c ft_putstr_fd.c ft_lstadd_back.c \
					ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
					ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
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


.PHONY:			all clean fclean re 
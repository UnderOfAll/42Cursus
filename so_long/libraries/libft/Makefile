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

NAME 			= libft.a

OBJ_DIR			= ../../objs/libft


LIBFT			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c \
	ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
	ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
	ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memmove.c \
	ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
	ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
	ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
	ft_printf.c ft_numbase_signed.c ft_numbase_unsigned.c get_next_line.c \
	get_next_line_utils.c \

LIBFT_OBJS		= $(patsubst %.c, $(OBJ_DIR)%.o, $(LIBFT))

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
AR				= ar rcs


all:			$(NAME)

$(NAME):		$(LIBFT_OBJS)
				@echo "Creating $(NAME) with objects $(LIBFT_OBJS)"
				@$(AR) $(NAME) $(LIBFT_OBJS)

$(OBJ_DIR)%.o: %.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "Cleaning object files..."
		@$(RM) $(LIBFT_OBJS)
		@echo "Object files cleaned."

fclean:			clean
		@echo "Cleaning library file..."
		@$(RM) $(NAME)
		@echo "Library file cleaned."

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
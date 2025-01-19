# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 15:29:36 by karocha-          #+#    #+#              #
#    Updated: 2025/01/18 17:57:31 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			= src/
OBJ_DIR			= obj/


SERVER			= $(SRC)server.c
CLIENT			= $(SRC)client.c
SRC_SERVER		= $(SRC)server
SRC_CLIENT		= $(SRC)client
OBJ_SERVER		= $(patsubst $(SRC)%.c,$(OBJ)server/%.o, $(SERVER))
OBJ_SERVER		= $(patsubst $(SRC)%.c,$(OBJ)client/%.o, $(CLIENT))

LIBFT_DIR		= /libft
LIBFT			= $(LIB_DIR)libft.a
LIBFT_OBJ		= $(OBJ)libft/

OBJS			= $(OBJ_SERVER) $(OBJS_CLIENT)

SERVER_NAME		= server
CLIENT_NAME		= client
NAME			= server

CC			= @cc
CFLAGS		= -g -Wall -Wextra -Werror
RM 			= rm -rf

#COLORS
RESET	= \033[0m
BOLD	= \033[1m
YELLOW	= \033[33m
RED		= \033[31m
GREEN	= \033[32m
CYAN 	= \033[36m

all:	$(LIBFT) server_all client_all

$(LIBFT):
				@$(MAKE) -C $(LIBFT_DIR)
				@chmod 644 $(LIBFT)

$(NAME): $(LIBFT) server_all client_all
				@echo "$(BOLD)$(YELLOW)Working on program...$(RESET)\n"
				@echo "$(BOLD)$(GREEN)Libft completed.$(RESET)\n"
				@$(CC) $(OBJS) -o $(NAME) $(LIBFT) || { echo "$(BOLD)$(RED) Failed to link$(RESET)"; exit 1; }

server_all:		$(OBJ_SERVER)
			@mkdir -p $(OBJ)server
			@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER_NAME) $(LIBFT)
			@echo "$(BOLD)$(GREEN)Server ready to go.$(RESET)\n"

$(OBJ)server/%.o: %(SRC)%.c
			@mkdir -p $(OBJ)server
			@$(CC) $(CFLAGS) -c $< -o $@

client_all:		$(OBJS_CLIENT) $(LIBFT)
			@mkdir -p $(OBJ)client
			@$(CC) $(CFLAGS) $(OBJ_CLIEnt) -o $(CLIENT_NAME) $(LIBFT)
			@echo "$(BOLD)$(GREEN)Client ready to go.$(RESET)\n"
			
$(OBJ)client/%.o: %(SRC)%.c
			@mkdir -p $(OBJ)client
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)
			@make --no-print-directory -C $(LIBFT_DIR) clean || { echo "$(BOLD)$(RED)Failed to clean libft.$(RESET)"; exit 1; }
			@echo "$(BOLD)$(GREEN)All objects cleaned with success!$(RESET)\n"
			
fclean: clean
			@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
			@make --no-print-directory -C $(LIBFT_DIR) clean || { echo "$(BOLD)$(RED)Failed to fclean libft.$(RESET)"; exit 1; }
			@echo "$(BOLD)$(GREEN)All executables cleaned with success!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re client server_all comp_start_all
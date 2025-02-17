# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 15:29:36 by karocha-          #+#    #+#              #
#    Updated: 2025/01/19 20:39:03 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER				=				$(SRC)server.c

CLIENT				=				$(SRC)client.c

SRC 				=				source/

OBJ					= 				objs/

SERVER_SRC			=				$(SRC)

SERVER_OBJS			=				$(patsubst $(SRC)%.c,$(OBJ)server/%.o,$(SERVER))

CLIENT_SRC			=				$(SRC)

CLIENT_OBJS			=				$(patsubst $(SRC)%.c,$(OBJ)client/%.o,$(CLIENT))

LIBFT_SRC			=				libft/

LIBFT				=				$(LIBFT_SRC)libft.a

LIBFT_OBJ			=				$(OBJ)libft/

OBJS				=				$(CLIENT_OBJS)\
									$(SERVER_OBJS)


CC					=				@cc

FLAGS				=				-Wall -Wextra -Werror

INCLUDE				=				-I include

SERVER_NAME			=				server

CLIENT_NAME			=				client

SERVER_NAME_BONUS 	=				server_bonus

CLIENT_NAME_BONUS 	= 				client_bonus

NAME				=				server

RM					= 				rm -rf

LOG_FILE			=				log.txt



RESET				=				\033[0m
BLACK 				=				\033[0;30m
RED					=				\033[0;31m
GREEN				=				\033[0;32m
YELLOW				=				\033[0;33m
BLUE				=				\033[0;34m
MAGENTA				=				\033[0;35m
CYAN				=				\033[0;36m

#------------------------------------- bold -------------------------------------
BLACK_B				=				\033[1;30m
RED_B				=				\033[1;31m
GREEN_B				=				\033[1;32m
YELLOW_B			=				\033[1;33m
BLUE_B				=				\033[1;34m
MAGENTA_B			=				\033[1;35m
CYAN_B				=				\033[1;36m

#---------------------------------- background ----------------------------------
BLACK_BK			=				\033[40m
RED_BK				=				\033[41m
GREEN_BK			=				\033[42m
YELLOW_BK			=				\033[43m
BLUE_BK				=				\033[44m
MAGENTA_BK			=				\033[45m
CYAN_BK				=				\033[46m
WHITE_BK			=				\033[47m

#===================================== LOGS =====================================

#------------------------------------ status ------------------------------------
OK					=				echo "\n$(GREEN_B)[ OK ] "
ERROR				=				echo "\n$(RED_B) [ ERROR ] "
WARNING				=				echo "\n$(YELLOW_B) [ WARNING ] "

log_error			=				@echo "$(shell date) - ERROR: $1" >> $(LOG_FILE)

#----------------------------------- messages -----------------------------------

COMP_START			=				@echo "\n🛠️ $(MAGENTA_B)MAKE: $(RESET)Starting the compilation...\n"

SERVER_READY		=				@$(OK) "🌐 $(CYAN_B)SERVER: $(RESET)Ready!\n"

SERVER_BONUS_READY	=				@$(OK) "🌐 $(CYAN_B)SERVER BONUS: $(RESET)Ready!\n"

LIBFT_READY			=				@$(OK) "🔗 $(CYAN_B)LIBFT: $(RESET)Libft Linked & Ready!\n"

CLIENT_READY		=				@$(OK) "💻 $(CYAN_B)CLIENT: $(RESET)Ready!\n"

CLIENT_BONUS_READY	=				@$(OK) "💻 $(CYAN_B)CLIENT BONUS: $(RESET)Ready!\n"

CLEANED				=				@echo	"\n🧹✨ $(MAGENTA_B)MAKE: $(RESET)Removed all the \".o\" files\n"

FCLEANED			=				@echo "\n🧹✨ $(MAGENTA_B)MAKE: $(RESET)Removed all the executables\n"

#===================================== RULES ====================================

all:	$(LIBFT) server_m client_m

$(LIBFT):
				@$(MAKE) -C $(LIBFT_SRC)
				@chmod 644 $(LIBFT)

$(NAME): $(LIBFT) comp_start server_m client_m
				@$(LIBFT_READY)
				@$(CC) $(OBJS) -o $(NAME) $(LIBFT) || { $(ERROR) "LINKING FAILED$(RESET)"; exit 1; }

bonus:	$(LIBFT) server_bonus_m client_bonus_m

comp_start:
				@$(COMP_START)

server_m:	$(SERVER_OBJS)
				@mkdir -p $(OBJ)server
				@$(CC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER_NAME) $(LIBFT)
				@$(SERVER_READY)

$(OBJ)server/%.o: $(SRC)%.c
				@mkdir -p $(OBJ)server
				@$(CC) $(FLAGS) -c $< -o $@

client_m:	$(CLIENT_OBJS) $(LIBFT)
				@mkdir -p $(OBJ)client
				@$(CC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME) $(LIBFT)
				@$(CLIENT_READY)

$(OBJ)client/%.o: $(SRC)%.c
				@mkdir -p $(OBJ)client
				@$(CC) $(FLAGS) -c $< -o $@

server_bonus_m:	$(SERVER_OBJS)
				@mkdir -p $(OBJ)server
				@$(CC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER_NAME_BONUS) $(LIBFT)
				@$(SERVER_READY)

client_bonus_m:	$(CLIENT_OBJS) $(LIBFT)
				@mkdir -p $(OBJ)client
				@$(CC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME_BONUS) $(LIBFT)
				@$(CLIENT_READY)

clean:
				@$(RM) $(OBJS)
				@make --no-print-directory -C $(LIBFT_SRC) clean || { $(ERROR) "Libft clean failed!\n"; exit 1; }
				@$(CLEANED)

fclean: clean
				@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)
				@make --no-print-directory -C $(LIBFT_SRC) fclean || { $(ERROR) "Libft fclean failed!\n"; exit 1; }
				@$(FCLEANED)

re: fclean all

.PHONY: all clean fclean re client server_m comp_start_m bonus server_bonus_m client_bonus_m

#all credits for this beautiful Makefile to MrRieff https://github.com/MrRieff

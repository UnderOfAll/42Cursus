# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:53:04 by karocha-          #+#    #+#              #
#    Updated: 2025/01/16 00:08:57 by karocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROGRAM NAME
NAME			= so_long

#DIRECTORY OF SOURCES
SRC_DIR 		= source/
PARSER_DIR		= $(SRC_DIR)parse_map/
DISPLAY_DIR		= $(SRC_DIR)display/

#DIRECTORY OF OBJECTS
OBJ_DIR			= objs/
LIBFT_OBJ_DIR	= $(OBJ_DIR)libft/
MLX_DIR 		= $(OBJ_DIR)minilibx/

#LIBRARIES
LIB_DIR			= libraries/
LIBFT_DIR		= $(LIB_DIR)libft/
MLX_OBJ_DIR		= $(LIB_DIR)minilibx/

#PATHS
MAIN_DIR		= $(SRC_DIR)so_long.c

PARSER			= $(PARSER_DIR)exit.c\
					$(PARSER_DIR)flood_fill.c\
					$(PARSER_DIR)helpers.c\
					$(PARSER_DIR)map_check.c\
					$(PARSER_DIR)map_utils.c\

DISPLAY			= $(DISPLAY_DIR)init.c\
					
					
#SOURCE (files to add)
SRCS = $(MAIN_DIR) $(PARSER) $(DISPLAY)
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

#COMPILATION AND REMOVE FLAGS
CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f
RM_F	= rm -rf

#LINK LIBRARIES
LINK = -L$(MLX_OBJ_DIR) -lmlx -L$(LIBFT_DIR) -lft -lm -lXext -lX11

#COLORS
RESET	= \033[0m
BOLD	= \033[1m
YELLOW	= \033[33m
RED		= \033[31m
GREEN	= \033[32m
CYAN 	= \033[36m

#CREATE EXECUTABLES
$(NAME): $(OBJS) $(LIBFT_DIR)libft.a $(MLX_OBJ_DIR)libmlx.a
		@echo "$(BOLD)$(YELLOW)Working on program...$(RESET)\n"
		@$(CC) $(OBJS) $(LINK) -o $(NAME) || { echo "$(BOLD)$(RED)ERROR: Failed linking$(RESET)"; exit 1; }
		@echo "$(BOLD)$(GREEN)$(NAME) Program created$(RESET)\n"

all: $(LIBFT_DIR)libft.a $(MLX_OBJ_DIR)libmlx.a $(NAME)

#COMPILE INDIVIDUAL OBJ FILES
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@echo "$(BOLD)$(YELLOW)COMPILING $<...$(RESET)\n"
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -c $< -o $@

#MAKE SURE LIBRARIES COMPILED
$(LIBFT_DIR)libft.a:
		@make -C $(LIBFT_DIR) || { echo "$(BOLD)$(RED)Error:Libft compilation failed$(RESET)"; exit 1; }
$(MLX_OBJ_DIR)libmlx.a:
		@make -C $(MLX_OBJ_DIR) || { echo "$(BOLD)$(RED)Error:Minilibx compilation failed$(RESET)"; exit 1; }

		
clean:
		@echo "$(BOLD)$(YELLOW)Cleaning objects..$(RESET)\n"
		@$(RM) $(OBJS)
		@make -C $(LIBFT_DIR) clean || { echo "$(BOLD)$(RED)Error: Libft failed to clean$(RESET)"; exit 1; }
		@make -C $(MLX_OBJ_DIR) clean || { echo "$(BOLD)$(RED)Error: Minilibx failed to clean$(RESET)"; exit 1; }
		@echo "$(BOLD)$(CYAN)All object files were cleaned$(RESET)\n"

fclean: clean
		@echo "$(BOLD)$(YELLOW)Cleaning all files...$(RESET)\n"
		@$(RM) $(NAME)
		@make -C $(LIBFT_DIR) clean || { echo "$(BOLD)$(RED)Error: Libft failed to clean$(RESET)"; exit 1; }
		@make -C $(MLX_OBJ_DIR) clean || { echo "$(BOLD)$(RED)Error: Minilibx failed to fclean$(RESET)"; exit 1; }
		@$(RM_F) $(OBJ_DIR)
		@echo "$(BOLD)$(CYAN)All files were cleaned$(RESET)\n"


re: fclean all

run: $(NAME)
	./$(NAME) maps/map1.ber

val: $(NAME)
	valgrind ./$(NAME) maps/map1.ber

.PHONY: all clean fclean re
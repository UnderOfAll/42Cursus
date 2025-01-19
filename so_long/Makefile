# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:53:04 by karocha-          #+#    #+#              #
#    Updated: 2025/01/18 15:34:58 by karocha-         ###   ########.fr        #
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
MLX_OBJ_DIR 	= $(OBJ_DIR)minilibx/

#LIBRARIES
LIB_DIR			= libraries/
LIBFT_DIR		= $(LIB_DIR)libft/
MLX_DIR			= $(LIB_DIR)minilibx/

#PATHS
MAIN_DIR		= $(SRC_DIR)so_long.c

PARSER			= $(PARSER_DIR)exit.c\
					$(PARSER_DIR)flood_fill.c\
					$(PARSER_DIR)helpers.c\
					$(PARSER_DIR)map_check.c\
					$(PARSER_DIR)map_utils.c\

DISPLAY			= $(DISPLAY_DIR)init.c\
					$(DISPLAY_DIR)put_images.c\
					$(DISPLAY_DIR)call_hooks.c\
					
#SOURCE (files to add)
SRCS = $(MAIN_DIR) $(PARSER) $(DISPLAY)
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

#COMPILATION AND REMOVE FLAGS
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f
RM_F	= rm -rf

#LINK LIBRARIES
LINK = -L$(LIBFT_DIR) -lmlx -L$(MLX_DIR) -lft -lm -lXext -lX11 -lz -lmlx_linux

#COLORS
RESET	= \033[0m
BOLD	= \033[1m
YELLOW	= \033[33m
RED		= \033[31m
GREEN	= \033[32m
CYAN 	= \033[36m

#CREATE EXECUTABLES
$(NAME): $(OBJS) $(LIBFT_DIR)libft.a $(MLX_DIR)libmlx.a
		@echo "$(BOLD)$(YELLOW)Working on program...$(RESET)\n"
		@$(CC) $(OBJS) $(LINK) -o $(NAME) || { echo "$(BOLD)$(RED)ERROR: Failed linking$(RESET)"; exit 1; }
		@echo "$(BOLD)$(GREEN)$(NAME) Program created$(RESET)\n"

all: $(LIBFT_DIR)libft.a $(MLX_DIR)libmlx.a $(NAME)

#COMPILE INDIVIDUAL OBJ FILES
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@echo "$(BOLD)$(YELLOW)COMPILING $<...$(RESET)\n"
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -c $< -o $@

#MAKE SURE LIBRARIES COMPILED
$(LIBFT_DIR)libft.a:
		@make -C $(LIBFT_DIR) || { echo "$(BOLD)$(RED)Error:Libft compilation failed$(RESET)"; exit 1; }
$(MLX_DIR)libmlx.a:
		@make -C $(MLX_DIR) || { echo "$(BOLD)$(RED)Error:Minilibx compilation failed$(RESET)"; exit 1; }

		
clean:
		@echo "$(BOLD)$(YELLOW)Cleaning objects..$(RESET)\n"
		@$(RM) $(OBJS)
		@make -C $(LIBFT_DIR) clean || { echo "$(BOLD)$(RED)Error: Libft failed to clean$(RESET)"; exit 1; }
		@make -C $(MLX_DIR) clean || { echo "$(BOLD)$(RED)Error: Minilibx failed to clean$(RESET)"; exit 1; }
		@echo "$(BOLD)$(CYAN)All object files were cleaned$(RESET)\n"

fclean: clean
		@echo "$(BOLD)$(YELLOW)Cleaning all files...$(RESET)\n"
		@$(RM) $(NAME)
		@make -C $(LIBFT_DIR) clean || { echo "$(BOLD)$(RED)Error: Libft failed to clean$(RESET)"; exit 1; }
		@make -C $(MLX_DIR) clean || { echo "$(BOLD)$(RED)Error: Minilibx failed to fclean$(RESET)"; exit 1; }
		@$(RM_F) $(OBJ_DIR)
		@echo "$(BOLD)$(CYAN)All files were cleaned$(RESET)\n"


re: fclean all

run: all
	./$(NAME) maps/map1.ber

val: all
	valgrind ./$(NAME) maps/map1.ber

.PHONY: all clean fclean re

#ALL CREDITS OF COLORS AND ECHO MAKEFILE TO MRRIEFF GITHUB FOLLOW HIM https://github.com/MrRieff
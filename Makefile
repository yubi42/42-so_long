# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jborner <jborner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 13:21:22 by jborner           #+#    #+#              #
#    Updated: 2024/07/22 14:02:55 by jborner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Werror -Wextra -g
NAME		= so_long

SRC_PATH 	= src/
OBJ_PATH 	= obj/
INCS    	= -Iinclude -I.mlx_linux
MLX		= .mlx_linux/libmlx.a

SRC		=	error_handling.c file_valid.c free_allocs.c main.c \
			map_init_structs.c map_set.c map_read.c map_valid.c \
			mlx_animation.c mlx_check_collect.c mlx_check_exit.c \
			mlx_check_img_path.c mlx_close.c mlx_count_steps.c \
			mlx_hooks.c mlx_img.c mlx_player_movement.c mlx_set_data.c \
			mlx_visualise.c \
			ft_printf.c ft_printf_utils.c ft_printf_err.c ft_printf_utils_err.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCS) -O3 -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(MLX):
	@if [ ! -d "./.mlx_linux/" ]; then \
		git clone git@github.com:42Paris/minilibx-linux.git ./.mlx_linux/; \
	fi
	@if [ ! -d "./.mlx_linux/build" ]; then \
		cd ./.mlx_linux/ && make; \
	fi

$(NAME): $(OBJ_PATH) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Linclude/.mlx_linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

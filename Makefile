# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglampor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:05:19 by aglampor          #+#    #+#              #
#    Updated: 2024/06/26 14:43:57 by aglampor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fract-ol

FLAG		=	-Wall -Wextra -Werror

MLX_FILE	=	libmlx.a

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./minilibx/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	 fractol.c draw.c fract_init.c help.c utils.c Julia.c\
			 Mandelbrot.c

SRC_DIR		=	./src/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

valgrind: mlx $(OBJ)
	@echo "\033[0;33m\nCOMPIL-OL..."
	@cc -g3 $(OBJ) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m$(NAME) executable created"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)..."
	@make -sC $(MLX_PATH)
	@echo "\033[1;32m$(MLX_FILE) created"

$(NAME): mlx $(OBJ)
	@echo "\033[0;33m\nCOMPILING 7O_OL..."
	@cc $(OBJ) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m$(NAME) executable created"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)..."
	@make clean -sC $(MLX_PATH)
	@echo "\033[1;32mDone"
	@echo "\033[0;31mDeleting Obj file in ./src/..."
	@rm -f $(OBJ)
	@echo "\033[1;32mDone"

fclean: clean
	@echo "\033[0;31mDeleting so_many executable..."
	@rm -f $(NAME)
	@echo "\033[1;32mDone"

re: fclean all

.PHONY: all clean fclean re

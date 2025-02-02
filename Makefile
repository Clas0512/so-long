NAME = so_long

NAME_MLX = mlx

CC = cc

OBJ = main.c

all: $(NAME_MLX) $(NAME)

$(NAME): $(OBJ)
	@make -C $(NAME_MLX) -s
	@$(CC) $(OBJ) -s -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# %.o: %.c
# 	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME_MLX):
	@git clone https://github.com/42Paris/minilibx-linux.git $(NAME_MLX)

clean:
	@rm $(NAME)

fclean: clean
	@make clean -C $(NAME_MLX) -s

re: fclean all

.PHONY: all clean fclean re
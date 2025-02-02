NAME = so_long

NAME_MLX = mlx_linux

NAME_GNL = gnl

GNL_SRCS = $(NAME_GNL)/get_next_line.c $(NAME_GNL)/get_next_line_utils.c

CC = cc

OBJ = main.c initialization/program_init.c initialization/set_map.c start_loop.c

all: $(NAME_MLX) $(NAME_GNL) $(NAME)

$(NAME): $(OBJ)
	mkdir -p include && cp -rf so_long.h $(NAME_GNL)/get_next_line.h include
	@make -C $(NAME_MLX) -s
	@$(CC) $(OBJ) $(GNL_SRCS) -s -Iinclude -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# %.o: %.c
# 	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME_MLX):
	@git clone https://github.com/42Paris/minilibx-linux.git $(NAME_MLX)

$(NAME_GNL):
	@git clone https://github.com/eceakdeemir/Get_next_line.git $(NAME_GNL)

clean:
	@rm -rf $(NAME)

fclean: clean
	@make clean -C $(NAME_MLX) -s
	@rm -rf include/

re: fclean all

.PHONY: all clean fclean re
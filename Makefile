NAME = so_long
NAME_MLX = mlx
NAME_GNL = gnl

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c initialization/program_init.c initialization/set_map.c \
	start_loop.c render/render_objects.c key_hooks/handle_key_hooks.c \
	move/player_moves.c move/end_game.c map_check/map_check.c \
	map_check/map_control_util.c map_check/map_control.c \
	map_check/map_shape.c utils/flood_zeroes.c

OBJ = $(SRCS:.c=.o)
GNL_SRCS = $(NAME_GNL)/get_next_line.c $(NAME_GNL)/get_next_line_utils.c

MLX_TAR = https://cdn.intra.42.fr/document/document/32169/minilibx_opengl.tgz

MLX_FLAGS = -L$(NAME_MLX) -lmlx -framework OpenGL -framework AppKit

all: $(NAME_MLX) $(NAME_GNL) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(GNL_SRCS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(NAME_MLX) -I$(NAME_GNL) -c $< -o $@

$(NAME_MLX):
	@echo "Downloading MiniLibX from 42..."
	@curl -L $(MLX_TAR) -o minilibx_opengl.tgz
	@tar -xzf minilibx_opengl.tgz
	@mv minilibx_opengl_*/ $(NAME_MLX)
	@rm minilibx_opengl.tgz
	@make -C $(NAME_MLX)

$(NAME_GNL):
	@git clone https://github.com/melihgoz/get_next_line.git $(NAME_GNL)

clean:
	@rm -rf $(OBJ) $(NAME)

fclean: clean
	@rm -rf $(NAME_MLX) $(NAME_GNL)
	@rm -rf mlx mlx_linux gnl

re: fclean all

.PHONY: all clean fclean re

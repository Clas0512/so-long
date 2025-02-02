#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_mlx_ptr
{
    void    *mlx;
    void    *win;
}               t_mlx_ptr;

typedef struct  s_image_addr
{
    void    *wall_img;
    void    *enemy_img;
    void    *floor_img;
    void    *exit_wall;
    void    *player_img;
    void    *collectable_img;
}               t_image_addr;

typedef struct  s_program_data
{
    char            **map;
    t_mlx_ptr       *mlx;
    unsigned short  map_x;
    unsigned short  map_y;
    t_image_addr    *image_addr;
}               t_program_data;

unsigned short program_init(t_program_data *data, char **argv);

#endif
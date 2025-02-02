#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <get_next_line.h>
#include <fcntl.h>

typedef struct  s_mlx_ptr
{
    void    *mlx_ptr;
    void    *win_ptr;
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
    int             texture_px_size;
}               t_program_data;

char            **set_map(char *map_file_name, t_program_data *data);
void            start_loop(t_program_data *data);
unsigned short  map_parse(t_program_data *data);
void            program_init(t_program_data *data, char *map_file_name);
unsigned short  program_perror(const char *error, unsigned short status_code);

#endif
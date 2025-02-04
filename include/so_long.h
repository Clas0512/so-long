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

typedef struct  s_player_attr
{
    void    *animation_ptr;
    void    *img_0;
    void    *img_1;
    void    *img_2;
    void    *img_3;
    void    *img_4;
    void    *img_5;
    void    *img_6;
    unsigned short position_x;
    unsigned short position_y;
}               t_player_attr;

typedef struct  s_image_addr
{
    t_player_attr   *player_attr;
    void    *wall_img;
    void    *enemy_img;
    void    *floor_img;
    void    *exit_wall;


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

int             render_map(t_program_data *data);
int             handle_key_hooks(int keycode, void *param);
char            **set_map(char *map_file_name, t_program_data *data);
void            start_loop(t_program_data *data);
void            move_right(t_program_data *data);
void            move_left(t_program_data *data);
void            move_down(t_program_data *data);
void            move_up(t_program_data *data);
void            render_objects(t_program_data *data, int x, int y);
void            program_init(t_program_data *data, char *map_file_name);
void            print_char_map(char **map);
unsigned short  map_parse(t_program_data *data);
unsigned short  program_perror(const char *error, unsigned short status_code);

#endif
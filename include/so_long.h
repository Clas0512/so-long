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

int				map_check(t_program_data *data);
int             render_map(t_program_data *data);
int             handle_key_hooks(int keycode, void *param);
char            **set_map(char *map_file_name, t_program_data *data);
void            start_loop(t_program_data *data);
void            move_right(t_program_data *data);
void            move_left(t_program_data *data);
void            move_down(t_program_data *data);
void            move_up(t_program_data *data);
void            render_objects(t_program_data *data, int x, int y, int counter_for_animation);
void            program_init(t_program_data *data, char *map_file_name);
void            print_char_map(char **map);
// unsigned short  map_parse(t_program_data *data);
unsigned short  program_perror(const char *error, unsigned short status_code);
unsigned short  wall_control(t_program_data *data); //
unsigned short  wall_control_2(t_program_data *data); //
unsigned short  map_exit_control(t_program_data *data); //
unsigned short  c_control(t_program_data *data); //
void	        zero_to_dot(t_program_data *data, char **fake_map, int p_x, int p_y); //
unsigned short  map_shape_correct(t_program_data *data); //
// unsigned short  is_reachable(t_program_data *data, int x, int y); //
void            flood_zeroes(t_program_data *data, char **fake_map); //
unsigned short	control_util(char **map, char c); //
void            free_map(char **map); //
char            **dup_map(char **map, int y); //
void find_player_coordinates(t_program_data *data, t_player_attr *player_attr);

#endif

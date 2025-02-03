#include <so_long.h>

static void    render_floor(t_program_data *data, int x, int y)
{
    mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
                    data->image_addr->floor_img, x * data->texture_px_size, y * data->texture_px_size);
}

static void    render_walls(t_program_data *data, int x, int y)
{
    if (data->map[y][x] == '1')
        mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
                        data->image_addr->wall_img, x * data->texture_px_size, y * data->texture_px_size);
}

static void    render_player(t_program_data *data, unsigned int time_manipulation, int x, int y)
{
    if (data->map[y][x] == 'P')
        mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
                    data->image_addr->player_attr->animation_ptr, x * data->texture_px_size, y * data->texture_px_size);
}

void    render_objects(t_program_data *data, int x, int y)
{
    // printf("[!!!]   DEBUG POINT  111   [!!!]\n");
    if (data->image_addr->player_attr->animation_ptr == NULL)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_0;
    // else
    //     player_animation_ptr = player_animation_set();

    render_floor(data, x, y);
    render_walls(data, x, y);
    render_player(data, 0, x, y);
}

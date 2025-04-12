#include "../so_long.h"

static void    render_floor(t_program_data *data, int x, int y)
{
    if (data->map[y][x] == '0')
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
    (void)time_manipulation;
    if (data->map[y][x] == 'P')
    {
        // mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
        //             data->image_addr->floor_img, x * data->texture_px_size, y * data->texture_px_size);
        mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
                    data->image_addr->player_attr->animation_ptr, x * data->texture_px_size, y * data->texture_px_size);
    }
}

void player_animation_set(t_program_data *data, int counter_for_animation)
{
    if (counter_for_animation % 560 == 0)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_0;
    else if (counter_for_animation % 480 == 0)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_6;
    else if (counter_for_animation % 400 == 0)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_5;
    else if (counter_for_animation % 320 == 0)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_4;
    else if (counter_for_animation % 240 == 0)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_3;
    else if (counter_for_animation % 160 == 0)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_2;
    else if (counter_for_animation % 80 == 0)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_1;
}

void    render_objects(t_program_data *data, int x, int y, int counter_for_animation)
{
    if (data->image_addr->player_attr->animation_ptr == NULL)
        data->image_addr->player_attr->animation_ptr = data->image_addr->player_attr->img_0;
    else
        player_animation_set(data, counter_for_animation);

    render_floor(data, x, y);
    render_walls(data, x, y);
    render_player(data, 0, x, y);
}

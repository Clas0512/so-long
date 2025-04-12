#include "so_long.h"

int render_map(t_program_data *data)
{
    int x;
    int y;
    // int new_y;
    static int counter_for_animation;

    // check_exited();
    x = 0;
    y = 0;
    while (y < data->map_y)
    {
        x = 0;
        // new_y = y * data->texture_px_size;
        while (x < data->map_x)
        {
            // mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
            //         data->image_addr->floor_img, new_x, new_y);
            render_objects(data, x, y, counter_for_animation);
            x++;
        }
        y++;
    }
    counter_for_animation++;
    if (counter_for_animation >= 560)
    counter_for_animation = 0;
    return (0);
}

void print_char_map(char **map)
{
    int s;
    int j;

    s = 0;
    while (map[s])
    {
        j = 0;
        while (map[s][j])
        {
            printf("%c", map[s][j]);
            j++;
        }
        printf("\n");
        s++;
    }
    printf("\n");
}

int    ft_exit(void *param)
{
    (void) param;
    exit(3);
}

void start_loop(t_program_data *data)
{
    mlx_new_image(data->mlx->mlx_ptr, data->map_y * 64, data->map_x * 64);
    render_map(data);
    mlx_hook(data->mlx->win_ptr, 2, 0, handle_key_hooks, data);
    // mlx_key_hook(data->mlx->win_ptr, handle_key_hooks, data);
    mlx_loop_hook(data->mlx->mlx_ptr, render_map, data);
    // mlx_hook(data->mlx->win_ptr, 17, 0, ft_exit, 0);
    mlx_loop(data->mlx->mlx_ptr);
    return ;
}
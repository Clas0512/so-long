#include <so_long.h>

static void render_map(t_program_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < data->map_y)
    {
        x = 0;
        while (x < data->map_x)
        {
            printf("x:%d y:%d\n", data->map_x, data->map_y);
            if (data->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
                    data->image_addr->wall_img, (x * data->texture_px_size), (y * data->texture_px_size));
            if (data->map[y][x] == '0')
                mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
                    data->image_addr->floor_img, (x * data->texture_px_size), (y * data->texture_px_size));
            x++;
        }
        y++;
    }

}

void start_loop(t_program_data *data)
{
    data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, (data->map_x * data->texture_px_size), (data->map_y * data->texture_px_size), "window");
    render_map(data);
}
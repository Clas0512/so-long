#include <so_long.h>

static void render_map(t_program_data *data)
{
    int x;
    int y;
    int new_x;
    int new_y;

    x = 0;
    y = 0;
    while (y < data->map_y)
    {
        x = 0;
        new_y = y * data->texture_px_size;
        while (x < data->map_x)
        {
            // mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
            //         data->image_addr->floor_img, new_x, new_y);
            render_objects(data, x, y);
            x++;
        }
        y++;
    }
}

void start_loop(t_program_data *data)
{
    mlx_key_hook(data->mlx->win_ptr, handle_key_hooks, data);
    render_map(data);
}
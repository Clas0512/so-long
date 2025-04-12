#include <so_long.h>

void find_player_coordinates(t_program_data *data, t_player_attr *player_attr)
{
    int i;
    int j;

    i = 0;
    printf("data->map_y: %d\n", data->map_y);
    while (i < data->map_y)
    {
        j = 0;
        while (j < data->map_x)
        {
            if (data->map[i][j] == 'P')
            {
                player_attr->position_x = j;
                player_attr->position_y = i;
            }
            j++;
        }
        i++;
    }
}


int handle_key_hooks(int keycode, void *param)
// int handle_key_hooks(void *param)
{
    t_program_data *data = param;
    find_player_coordinates(data, data->image_addr->player_attr);
    if (keycode == 100) // D
        move_right(data);
    if (keycode == 97) // A
        move_left(data);
    if (keycode == 115) // S
        move_down(data);
    if (keycode == 119) // W
        move_up(data);
    if (keycode == 65307) // ESC
        exit(44);
    // mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
    // render_map(data);
    // printf("keycode: %d\n", keycode);
    return (0);
}
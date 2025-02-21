#include <so_long.h>

void    move_right(t_program_data *data)
{
    t_player_attr *need = data->image_addr->player_attr;
    if (data->map[need->position_y][need->position_x + 1] != '1')
    {
        data->map[need->position_y][need->position_x + 1] = 'P';
        data->map[need->position_y][need->position_x] = '0';
    }
    print_char_map(data->map);
}

void            move_left(t_program_data *data)
{
    t_player_attr *need = data->image_addr->player_attr;
    if (data->map[need->position_y][need->position_x - 1] != '1')
    {
        data->map[need->position_y][need->position_x - 1] = 'P';
        data->map[need->position_y][need->position_x] = '0';
    }
    print_char_map(data->map);
}

void            move_down(t_program_data *data)
{
    t_player_attr *need = data->image_addr->player_attr;

    if (data->map[need->position_y + 1][need->position_x] != '1')
    {
        data->map[need->position_y + 1][need->position_x] = 'P';
        data->map[need->position_y][need->position_x] = '0';
    }
    print_char_map(data->map);

}

void            move_up(t_program_data *data)
{
    t_player_attr *need = data->image_addr->player_attr;
    if (data->map[need->position_y - 1][need->position_x] != '1')
    {
        data->map[need->position_y - 1][need->position_x] = 'P';
        data->map[need->position_y][need->position_x] = '0';
    }
    print_char_map(data->map);
    

}


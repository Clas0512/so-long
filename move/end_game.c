#include <so_long.h>

unsigned short	end_game(t_program_data *data)
{
	if (data->map[data->image_addr->player_attr->position_y]
		[data->image_addr->player_attr->position_x] == 'E')
	{
		write(1, "Game finished!!\n", 16);
		return (1);
	}
	return (0);
}

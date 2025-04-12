#include <so_long.h>


void	zero_to_dot(t_program_data *data, char **fake_map, int p_x, int p_y)
{
	printf("sege\n");
	for (int i = 0; i < fake_map[i]; i++)
	{	
		printf("%s\n", fake_map[i]);
	}
	if (p_x != data->map_x && p_y != data->map_y &&
			fake_map[p_y][p_x] != '1' && fake_map[p_y][p_x] != '.')
	{
		fake_map[p_y][p_x] = '.';
		zero_to_dot(data, fake_map, p_x, p_y - 1);
		zero_to_dot(data, fake_map, p_x, p_y + 1);
		zero_to_dot(data, fake_map ,p_x + 1, p_y);
		zero_to_dot(data, fake_map ,p_x - 1, p_y);		
	}
	// if (c_control(data) != 1)
	// {
	// 	write(1, "Zero\n", 5); // ERROR MESSAGE
	// 	return ;
	// }
	return ;
}

void    flood_zeroes(t_program_data *data, char **fake_map)
{
    zero_to_dot(data, fake_map, data->image_addr->player_attr->position_x,
				data->image_addr->player_attr->position_y);
}


#include "../so_long.h"

unsigned short  wall_control(t_program_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_x)
	{
		if (data->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->map_y)
	{
		if (data->map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

unsigned short  wall_control_2(t_program_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_y)
	{
		if (data->map[i][data->map_x - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->map_x)
	{
		if (data->map[data->map_y - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}


// unsigned short  is_reachable(t_program_data *data, int x, int y)
// {
// 	int	i;

// 	i = 0;
// 	if (data->map[x][y + 1] == '1')
// 		i++;
// 	if (data->map[x + 1][y] == '1')
// 		i++;
// 	if (data->map[x][y - 1] == '1')
// 		i++;
// 	if (data->map[x - 1][y] == '1')
// 		i++;
// 	if (i == 4)
// 	{
// 		write();// ERROR MESSAGE
// 		return (0);
// 	}
// 	return (1);
// }

unsigned int	control_util(char **map, char c)
{
	int i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	j = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	change_value(t_program_data *data, char **fake_map, char change, char from)
{
	int		i;
	int		j;

	i = 1;
	while (i < data->map_y - 1)
	{
		j = 1;
		while (j < data->map_x - 1)
		{
			if (fake_map[i][j] == from)
				fake_map[i][j] = change;
			j++;
		}
		i++;
	}
}

unsigned short  c_control(t_program_data *data)
{
	char	**fake_map;

	fake_map = dup_map(data->map, data->map_y);
	if (!fake_map)
	{
		free_program_init(5, data);
		return (0);
	}
	change_value(data, fake_map, '1', 'E');
	if (control_util(fake_map, 'C') > 0)
	{
		flood_zeroes(data, fake_map);
		if (control_util(fake_map, 'C') > 0)
		{
			free_map(fake_map);
			write(1, "c_cont\n", 7); // ERROR MESSAGE
			return (0);
		}
	}
	free_map(fake_map);
	return (1);
}

unsigned short  map_exit_control(t_program_data *data)
{
	char	**fake_map;

	fake_map = dup_map(data->map, data->map_y);
	if (control_util(fake_map, 'E') == 1)
	{
		flood_zeroes(data, fake_map);
		if (control_util(fake_map, 'E') != 0)
		{
			free_map(fake_map);
			write(1, "e_cont\n", 7); //ERROR MESSAGE
			return (0);
		}
	}
	else
	{
		free_map(fake_map);
		return (0);
	}
	free_map(fake_map);
	return (1);
}

#include "../so_long.h"

unsigned short  map_shape_correct(t_program_data *data)
{
    int i;
	int	j;
	int	previous_len;

	i = 1;
	j = 0;
	if (data->map_x >= 3 || data->map_y >= 3)
	{
		while (data->map[i])
		{
			previous_len = ft_strlen(data->map[0]);
			j = 0;
			while (data->map[i][j])
				j++;
			if (previous_len != j)
			{
				write(1, "map_shape\n", 10); // ERROR MESSAGE
				return (0);
			}
			i++;
		}
	}
	else
		return (0);
	return (1);
}

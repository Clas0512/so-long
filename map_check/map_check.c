#include "../so_long.h"

int	map_check(t_program_data *data)
{
    find_player_coordinates(data, data->image_addr->player_attr);
    printf("x=%d\ny=%d\n", data->image_addr->player_attr->position_x, data->image_addr->player_attr->position_y);
	if (wall_control(data) != 1)
		return (0);
	if (wall_control_2(data) != 1)
		return (0);
	if (c_control(data) != 1)
		return (0);
	printf("debugg\n");
	if (map_exit_control(data) != 1)
		return (0);
	if (player_check(data) != 1)
		return (0);
	return (1);
}

char            **dup_map(char **map, int y)
{
	int	i;
	char **ptr;

	i = 0;
	ptr = (char**) malloc(sizeof(char *) * (y + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < y)
	{
		ptr[i] = ft_strdup(map[i]);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

void            free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}
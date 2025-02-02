#include <so_long.h>

static unsigned short free_program_init(unsigned short status_code, t_program_data *data)
{
    if (status_code > 3)
        free(data->image_addr);
    if (status_code > 2)
        free(data->mlx);
    if (status_code > 1)
        free(data);
    return (1);
}

unsigned short program_init(t_program_data *data, char *map_file_name)
{
    data = malloc(sizeof(t_program_data));
    if (!data)
        return (free_program_init(1, data));
    data->mlx = malloc(sizeof(t_mlx_ptr));
    if (!data->mlx)
        return (free_program_init(2, data));
    data->image_addr = malloc(sizeof(t_image_addr));
    if (!data->image_addr)
        return (free_program_init(3, data));

    data->map = set_map(map_file_name, data);
    if (!data->map)
        return (free_program_init(4, data));
    data->map_y = ft_strlen(*(data->map));

    return (0);
}
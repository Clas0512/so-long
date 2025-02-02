#include <so_long.h>

unsigned short program_init(t_program_data *data, char **argv)
{
    data = malloc(sizeof(t_program_data));
    data->mlx = malloc(sizeof(t_mlx_ptr));
    data->image_addr = malloc(sizeof(t_image_addr));

    data->map = set_map(argv);
    data->map_x = ft_strlen(data->map);
    data->map_y = ft_strlen(*(data->map));

    return (0);
}
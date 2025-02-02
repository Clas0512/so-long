#include <so_long.h>

static void free_program_init(unsigned short status_code, t_program_data *data)
{
    if (status_code > 3)
        free(data->image_addr);
    if (status_code > 2)
        free(data->mlx);
    if (status_code > 1)
        free(data);
    // return (NULL);
}

static unsigned short images_init(t_program_data *data)
{
    char *wall = "textures/bricks.xpm";
    char *floor = "textures/mud.xpm";

    data->texture_px_size = 64;

    data->image_addr->wall_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/bricks.xpm", &(data->texture_px_size), &(data->texture_px_size));
    data->image_addr->floor_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/mud.xpm", &(data->texture_px_size), &(data->texture_px_size));
    // data->image_addr->player_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/black-cat/", &(data->texture_px_size), &(data->texture_px_size));
    if (!data->image_addr->floor_img || !data->image_addr->wall_img)
        return (program_perror("(program_init.c:image_addr_init()) -> Couldn't load image_addr, please look up details.", 1));
    return (0);
}

void    program_init(t_program_data *data, char *map_file_name)
{
    // data = malloc(sizeof(t_program_data));
    // if (!data)
    //     return (free_program_init(1, data));
    data->mlx = malloc(sizeof(t_mlx_ptr));
    if (!data->mlx)
        return (free_program_init(2, data));
    data->mlx->mlx_ptr = mlx_init();
    data->image_addr = malloc(sizeof(t_image_addr));
    if (!data->image_addr)
        return (free_program_init(3, data));

    data->map = set_map(map_file_name, data);
    if (!data->map)
        return (free_program_init(4, data));
    data->map_x = ft_strlen(*(data->map));
    if (images_init(data))
        return (free_program_init(4, data));
    // return (data);
}
#include <so_long.h>

static void free_program_init(unsigned short status_code, t_program_data *data)
{
    if (status_code > 4)
        free(data->image_addr->player_attr);
    if (status_code > 3)
        free(data->image_addr);
    if (status_code > 2)
        free(data->mlx);
    if (status_code > 1)
        free(data);
    printf("FREE PROGRAM INIT\n");
    // return (NULL);
}

static void images_player_init(t_program_data *data)
{
    data->image_addr->player_attr->animation_ptr = NULL;
    data->image_addr->player_attr->img_0 = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/black-cat/tile000.xpm", &(data->texture_px_size), &(data->texture_px_size));
    data->image_addr->player_attr->img_1 = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/black-cat/tile001.xpm", &(data->texture_px_size), &(data->texture_px_size));
    data->image_addr->player_attr->img_2 = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/black-cat/tile002.xpm", &(data->texture_px_size), &(data->texture_px_size));
    data->image_addr->player_attr->img_3 = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/black-cat/tile003.xpm", &(data->texture_px_size), &(data->texture_px_size));
    data->image_addr->player_attr->img_4 = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/black-cat/tile004.xpm", &(data->texture_px_size), &(data->texture_px_size));
    data->image_addr->player_attr->img_5 = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/black-cat/tile005.xpm", &(data->texture_px_size), &(data->texture_px_size));
    data->image_addr->player_attr->img_6 = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/black-cat/tile006.xpm", &(data->texture_px_size), &(data->texture_px_size));
}

static unsigned short images_init(t_program_data *data)
{
    data->texture_px_size = 64;
    images_player_init(data);
    data->image_addr->wall_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/bricks.xpm", &(data->texture_px_size), &(data->texture_px_size));
    data->image_addr->floor_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "textures/grass.xpm", &(data->texture_px_size), &(data->texture_px_size));
    

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
        free_program_init(2, data);
    data->mlx->mlx_ptr = mlx_init();
    data->image_addr = malloc(sizeof(t_image_addr));
    if (!data->image_addr)
        free_program_init(3, data);
    data->image_addr->player_attr = malloc(sizeof(t_player_attr));
    if (!data->image_addr->player_attr)
        free_program_init(4, data);

    data->map = set_map(map_file_name, data);
    if (!data->map)
        free_program_init(5, data);
    data->map_x = ft_strlen(*(data->map));
    if (images_init(data))
        free_program_init(5, data);
}
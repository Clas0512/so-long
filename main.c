#include <so_long.h>

unsigned short  program_perror(const char *error, unsigned short status_code)
{
    perror(error);
    return (status_code);
}

int main(int argc, char **argv)
{
    t_program_data *data;

    data = malloc(sizeof(t_program_data));
    printf("looptan hemen sonra\n");
    if (!data)
        exit(31);
    // duzenlencek
    if (argc != 2)
        return (program_perror("(main.c:main()) -> Invalid input, please provide a map argument that it's ending with .ber extension.", 1));
    program_init(data, argv[1]);
    if (!data)
        return (program_perror("(main.c:main()) -> Unknown initialization error, please look up details.", 2));
    int size_x = data->map_x * data->texture_px_size;
    int size_y = data->map_y * data->texture_px_size;
    data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, size_x, size_y, "window");
    // if (map_check(data))
    start_loop(data);
    mlx_loop(data->mlx->mlx_ptr);
    return (0);
}
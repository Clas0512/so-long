#include <so_long.h>

unsigned short  program_perror(const char *error, unsigned short status_code)
{
    perror(error);
    return (status_code);
}

int main(int argc, char **argv)
{
    t_program_data *data;

    if (argc != 2)
        return (program_perror("(main.c:main()) -> Invalid input, please provide a map argument that it's ending with .ber extension.", 1));

    if (program_init(data, argv[1]))
        return (program_perror("(main.c:main()) -> Unknown initialization error, please look up details.", 2));
    printf("--------------------------- OKAY BROOOO ---------------------------\n");
    if (map_parse(data))
    // map_check();
    // start_loop();
    return (0);
}
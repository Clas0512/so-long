#include "mlx/mlx.h"
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        perror("(main.c:main()) -> Invalid input, please provide a map argument that it's ending with .ber extension.");
        return (1);
    }

    return (0);
}
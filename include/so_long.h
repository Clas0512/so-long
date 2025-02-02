#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_program_data
{
    char **map;
}               t_program_data;

int program_init(t_program_data *data);

#endif
#include "../so_long.h"

unsigned short	end_game(t_program_data *data)
{
	if (control_util(data->map, 'E') == 0)
	{
		
		write(1, "You WIN!!\n", 10);
		return (1);
	}
	return (0);
}

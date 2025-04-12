#include <so_long.h>

void	control_util_util(int count, char c)
{
	if (c == 'P' && count != 1)
	{
		write(1, "No more than 1 player\n", 22);
	}
	else if (c == 'C' && count == 0)
	{
		write(1, "Should be at least 1 collectable\n", 33);
	}
	else if (c == 'E' && count != 1)
	{
		write(1, "Must be 1 exit\n", 15);
	}
}

unsigned short player_check(t_program_data *data)
{
	int	p_count;

	p_count = control_util(data->map, 'P');
	if (p_count != 1)
	{
		write(1, "No more than 1 player allowed\n", 30);
		return (0);
	}
	return (1);
}

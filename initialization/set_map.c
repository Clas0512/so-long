#include "../so_long.h"

static unsigned int  ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	return (0);
}

static unsigned short check_map_name(const char *map_name)
{
    unsigned int    i;

    i = ft_strlen(map_name);
    if (i <= 4)
        return (program_perror("(set_map.c:check_map_name) -> Invalid map name, please provide a valid map name. (Ex. map.ber, example.ber, valid_map.ber).", 1));
    if (ft_strncmp(&(map_name[i - 4]), ".ber", 4))
        return (program_perror("(set_map.c:check_map_name) -> Invalid map name, please provide a valid map name. (Ex. map.ber, example.ber, valid_map.ber).", 1));
    return (0);
}

static unsigned short map_line_counter(const char *map_file_name)
{
    int             map_file_fd;
    char            *tmp;
    unsigned short  i;

    i = 0;
    map_file_fd = open(map_file_name, O_RDONLY);
    if (map_file_fd < 0)
        return (program_perror("(set_map.c:set_map) -> Can't open map file. Please make sure map is exist.", 1));
    tmp = get_next_line(map_file_fd);
    while (tmp)
    {
        free(tmp);
        tmp = get_next_line(map_file_fd);
        i++;
    }
    close(map_file_fd);
    return (i);
}

//bu degiscek donusu error icin
char    *delete_new_lines(char *map_line)
{
    char *tmp;

    if (ft_strchr(map_line, '\n') != -1)
    {
        tmp = ft_substr(map_line, 0, ft_strchr(map_line, '\n'));
        if (!tmp)
            return (NULL);
        free(map_line);
    }
    else
        return (map_line);
    return (tmp);
}

char **set_map(char *map_file_name, t_program_data *data)
{
    int     i;
    char    **map;
    int     map_file_fd;

    check_map_name(map_file_name);
    data->map_y = map_line_counter(map_file_name);

    map = malloc(sizeof(char *) * (data->map_y + 1));
    if (!map)
        return (NULL);
    map[data->map_y] = NULL;
    map_file_fd = open(map_file_name, O_RDONLY);
    if (map_file_fd < 0)
    {
        program_perror("(set_map.c:set_map) -> Can't open map file. Please make sure map is exist.", 1);
        free(map);
        return (NULL);
    }

    i = 0;
    map[i] = get_next_line(map_file_fd);
    while (map[i])
    {
        map[i] = delete_new_lines(map[i]);
        // mapin acildigi yerler olabilir onlari da freeleyip cikman gerekiyor
        if (!map[i])
            return (NULL);
        i++;
        map[i] = get_next_line(map_file_fd);
    }
    // print_char_map(map);
    data->map_x = ft_strlen(map[0]);
    close(map_file_fd);
    // print_char_map(map);
    return (map);
}

// another way gibi bir sey
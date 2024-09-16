#include "../cub3D.h"

// strbase gets freed!
char	*concat_line(char *strbase, char *stradd)
{
	size_t			i;
	size_t			j;
	const size_t	len = ft_strlen(strbase) + ft_strlen(stradd);
	char			*new_str;

	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (strbase[j])
		new_str[i++] = strbase[j++];
	j = 0;
	while (stradd[j])
		new_str[i++] = stradd[j++];
	new_str[i] = '\0';
	free(strbase);
	return (new_str);
}

bool	check_map(t_cubed *cubed, char *map)
{
	char	*line;
	char	*concat;

	cubed->map_fd = open(map, O_RDONLY);
	if (cubed->map_fd == -1)
		return (EXIT_FAILURE);
	while (true)
	{
		line = get_next_line(cubed->map_fd);
		if (!line)
			return (close(cubed->map_fd), EXIT_FAILURE);
		if (line[0] == '\0')
			break ;
		concat = concat_line(concat, line);
		if (!concat)
			return (free(line), close(cubed->map_fd), EXIT_FAILURE);
		free(line);
	}
	close(cubed->map_fd);
	free(line);
	cubed->map = ft_split(concat, '\n');
	if (!cubed->map)
		return (free(concat), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

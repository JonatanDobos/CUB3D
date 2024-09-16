#include "../cub3D.h"

// strbase gets freed!
char	*concat_line(char *strbase, char *stradd)
{
	size_t			i;
	size_t			j;
	const size_t	len = ft_nstrlen(strbase) + ft_nstrlen(stradd);
	char			*new_str;

	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (strbase && strbase[j])
		new_str[i++] = strbase[j++];
	j = 0;
	while (stradd && stradd[j])
		new_str[i++] = stradd[j++];
	new_str[i] = '\0';
	free(strbase);
	return (new_str);
}

static int	parse_map(t_cubed *cubed, char *map_file)
{
	char	*line;
	char	*concat;

	cubed->map_fd = open(map_file, O_RDONLY);
	if (cubed->map_fd == -1)
		return (e_msg("Error opening map file", true), FAIL);
	concat = NULL;
	while (true)
	{
		line = get_next_line(cubed->map_fd);
		if (!line)
			return (free(concat), close(cubed->map_fd), MERR);
		if (line[0] == '\0')
			break ;
		concat = concat_line(concat, line);
		if (!concat)
			return (free(line), close(cubed->map_fd), MERR);
		free(line);
	}
	close(cubed->map_fd);
	cubed->map = ft_split(concat, '\n');
	free_va(2, concat, line);
	if (!cubed->map)
		return (MERR);
	return (OK);
}

static bool	check_ends(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] == '1')
		++i;
	if (line[i] != '\0')
		return (FAIL);
	return (OK);
}

static bool	check_map(t_cubed *cubed)
{
	const size_t	len = ft_nstrlen(cubed->map[0]);
	size_t			i;

	i = 0;
	while (cubed->map[i] != NULL)
		++i;
	if (i < 3 || len < 3)
		return (e_msg("Map error too small", false), FAIL);
	while (i-- > 0)
	{
		if (ft_strlen(cubed->map[i]) != len
			|| cubed->map[i][0] != '1' || cubed->map[i][len - 1] != '1')
			return (printf("Map error at line %zu\n", i + 1), FAIL);
		if ((i == len - 1 || i == 0) && check_ends(cubed->map[i]))
			return (printf("Map error at line %zu\n", i + 1), FAIL);
	}
	return (OK);
}

bool	map_check(t_cubed *cubed, char *map_file, int argc)
{
	const size_t	len = ft_nstrlen(map_file);

	if (argc != 2 || len < 5 || ft_strncmp(map_file + len - 4, ".cub", 4))
		return (printf("%s\n", USAGE_PROMPT), FAIL);
	if (parse_map(cubed, map_file) == FAIL)
		return (FAIL);
	if (parse_map(cubed, map_file) == MERR)
		return (e_msg("Error mallocing memory", true), FAIL);
	if (check_map(cubed))
		return (cleanup(cubed), FAIL);
	return (OK);
}

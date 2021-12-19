/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:52:43 by rlachau           #+#    #+#             */
/*   Updated: 2021/12/18 10:40:22 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_extension(char *map)
{
	int	len;
	int	i;

	len = ft_strlen(map);
	i = len - 4;
	if (len < 5)
		return (0);
	if (map[i] == '.' && map[i + 1] == 'b' && map[i + 2] == 'e'
		&& map[i + 3] == 'r')
		return (1);
	return (0);
}

int	valid_walls(char *line, int line_num, int len)
{
	int		i;

	i = 0;
	if (line_num == -1 || line_num == 0)
	{
		while (line[i] == '1')
		{
			i++;
			if ((line[i] == '\n' && i == len -1) || (!line[i] && line_num == -1
				&& !ft_strchr(line, '\n')))
			return (1);
		}
		return (0);
	}
	if (line[0] == '1' && line[len - 1] == '\n'
		&& line[len - 2] == '1' && line_num != 1)
		return (1);
	return (0);
}

int	valid_chars(char *line, t_mlx_data *g)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'E')
			g->char_count.e++;
		else if (line[i] == 'C')
			g->char_count.c++;
		else if (line[i] == 'P')
			g->char_count.p++;
		else if (line[i] == '0' || line[i] == '1' || line[i] == '\n')
			continue ;
		else
			return (0);
	}
	return (1);
}

int	ft_parse_map(char *map, t_mlx_data *g)
{
	const int		fd = open(map, O_RDONLY);		
	char			*line;
	int				y;
	size_t			x;

	y = 0;
	line = get_next_line(fd);
	if (!line || fd < 1)
		return (0);
	x = ft_strlen(line);
	set_zero(g);
	free(line);
	while (line && ++y)
	{
		if ((valid_walls(line, y, x) && valid_chars(line, g)
			&& ft_strlen(line) == x) || valid_walls(line, -1, x))
		{	
			line = get_next_line(fd);
			free(line);
		}
		else
			return (0);
	}
	if (!g->char_count.c || !g->char_count.e || g->char_count.p != 1
		|| !valid_extension(map))
		return (0);
	set_data(x, y, g);
	free(line);
	return (1);
}

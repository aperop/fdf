/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:03:33 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/02/13 01:45:06 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_higth_width(t_map *map)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error");
	line = get_next_line(fd);
	if (!line)
		ft_error("Error");
	split = ft_split(line, ' ');
	while (split[map->width])
		free(split[map->width++]);
	free(split[map->width]);
	free(split);
	while (line)
	{
		free(line);
		line = NULL;
		++(map->higth);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

static int	parse_z_color(t_map *map, char **split, int row)
{
	int		column;
	char	**z_color;

	column = 0;
	while (column < map->width)
	{
		z_color = ft_split(split[column], ',');
		map->data[row][column] = (t_data *)malloc(sizeof(t_data));
		map->data[row][column]->z = ft_atoi(z_color[0]);
		map->data[row][column]->color = 0xffffff;
		if (z_color[1] != NULL)
			map->data[row][column]->color = hex2int(z_color[1]);
		free(split[column]);
		free(z_color[0]);
		free(z_color[1]);
		free(z_color);
		++column;
	}
	return (column);
}

static void	parse_data(t_map *map)
{
	int		fd;
	int		row;
	char	*line;
	char	**split;
	int		i;

	map->data = (t_data ***)malloc(sizeof(t_data **) * map->higth);
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return ;
	row = 0;
	while (row < map->higth)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		map->data[row] = (t_data **)malloc(sizeof(t_data *) * map->width);
		i = 0;
		i = parse_z_color(map, split, row);
		free(line);
		free(split[i]);
		free(split);
		++row;
	}
	close(fd);
}

void	parse(t_map *map)
{
	map->width = 0;
	map->higth = 0;
	map->shift_x = SIZE_X / 2;
	map->shift_y = SIZE_Y / 5;
	parse_higth_width(map);
	parse_data(map);
}

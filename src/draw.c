/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:03:26 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/02/13 02:01:06 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(float *xy[4], t_map *map)
{
	(*xy)[0] *= map->zoom;
	(*xy)[1] *= map->zoom;
	(*xy)[2] *= map->zoom;
	(*xy)[3] *= map->zoom;
}

static void	shift(float *xy[4], t_map *map)
{
	(*xy)[0] += map->shift_x;
	(*xy)[1] += map->shift_y;
	(*xy)[2] += map->shift_x;
	(*xy)[3] += map->shift_y;
}

static void	iso(float xy[4], t_map *map)
{
	int		color;
	int		z;
	int		z1;

	z = map->data[(int)xy[1]][(int)xy[0]]->z;
	z1 = map->data[(int)xy[3]][(int)xy[2]]->z;
	color = map->data[(int)xy[1]][(int)xy[0]]->color;
	if (z > z1)
		color = map->data[(int)xy[3]][(int)xy[2]]->color;
	zoom(&xy, map);
	if (map->projection == ISOMETRIC)
	{
		rotation(&(xy[0]), &(xy[1]), z);
		rotation(&(xy[2]), &(xy[3]), z1);
	}
	shift(&xy, map);
	bresenham(&xy, map, color);
}

static void	draw_lines(float xy[4], int h, int w, t_map *map)
{
	if (w < map->width - 1)
	{
		xy[0] = w;
		xy[1] = h;
		xy[2] = w + 1;
		xy[3] = h;
		iso(xy, map);
	}
	if (h < map->higth - 1)
	{
		xy[0] = w;
		xy[1] = h;
		xy[2] = w;
		xy[3] = h + 1;
		iso(xy, map);
	}
}

void	draw(t_map *map)
{
	int		h;
	int		w;
	float	xy[4];

	h = 0;
	while (h < map->higth)
	{
		w = 0;
		while (w < map->width)
		{
			draw_lines(xy, h, w, map);
			++w;
		}
		++h;
	}
}

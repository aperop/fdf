/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:03:37 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/02/13 01:28:49 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(const char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

int	ft_exit(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	while (i < map->higth)
	{
		j = 0;
		while (j < map->width)
		{
			free(map->data[i][j]);
			j++;
		}
		free(map->data[i]);
		i++;
	}
	free(map->data);
	free(map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	hex2int(char *hex)
{
	int	val;
	int	byte;

	val = 0;
	while (*hex)
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}

void	bresenham(float *xy[4], t_map *map, int color)
{
	float	x_s;
	float	y_s;
	int		max;

	x_s = (*xy)[2] - (*xy)[0];
	y_s = (*xy)[3] - (*xy)[1];
	max = fmaxf(fabsf(x_s), fabsf(y_s));
	x_s /= max;
	y_s /= max;
	while ((int)((*xy)[0] - (*xy)[2]) || (int)((*xy)[1] - (*xy)[3]))
	{
		(*xy)[0] += x_s;
		(*xy)[1] += y_s;
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, (*xy)[0], (*xy)[1], color);
	}
}

void	rotation(float *x, float *y, int z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * COS30;
	*y = -z + (prev_x + prev_y) * SIN30;
}

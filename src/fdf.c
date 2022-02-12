/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:08:19 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/02/13 02:00:54 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	shift_zoom(int key, t_map *map)
{
	if (key == I)
	{
		map->shift_x = SIZE_X / 2;
		map->shift_y = SIZE_Y / 5;
		map->projection = ISOMETRIC;
	}
	else if (key == P)
	{
		map->shift_x = SIZE_X / 5;
		map->shift_y = SIZE_Y / 5;
		map->projection = PARALLEL;
	}
}

int	redraw(int key, t_map *map)
{
	if (key == UP)
		map->shift_y += 20;
	else if (key == DOWN)
		map->shift_y -= 20;
	else if (key == LEFT)
		map->shift_x += 20;
	else if (key == RIGTH)
		map->shift_x -= 20;
	else if (key == ZOOM_IN)
		map->zoom += 1;
	else if (key == ZOOM_OUT)
		map->zoom -= 1;
	else if (key == ESCAPE)
		ft_exit (map);
	else if (key == I || key == P)
		shift_zoom(key, map);
	else
		return (0);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename>\n", STDERR_FILENO);
		return (-1);
	}
	map = (t_map *)malloc(sizeof(t_map));
	map->filename = argv[1];
	parse(map);
	ft_putstr_fd("PARSED\n", 1);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, SIZE_X, SIZE_Y, "FDF");
	map->projection = ISOMETRIC;
	map->zoom = ZOOM;
	draw(map);
	ft_putstr_fd("DRAWN\n", 1);
	mlx_key_hook(map->win_ptr, redraw, map);
	mlx_hook(map->win_ptr, DESTROY_NOTIFY, NO_EVENT_MASK, ft_exit, map);
	mlx_loop(map->mlx_ptr);
	ft_exit(map);
	return (0);
}

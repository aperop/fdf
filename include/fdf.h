/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:03:23 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/02/13 01:29:05 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 10

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/includes/libft.h"
# include "math.h"
# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK 1L
# define ZOOM 20
# define COS30 0.86602540378
# define SIN30 0.5
# define SIZE_X 1080
# define SIZE_Y 720
# define LEFT 65361
# define RIGTH 65363
# define UP 65362
# define DOWN 65364
# define ZOOM_IN 61
# define ZOOM_OUT 45
# define ESCAPE 65307
# define I 105
# define P 112

enum
{
	ISOMETRIC,
	PARALLEL
};

typedef struct s_data
{
	int			z;
	int			color;
}				t_data;

typedef struct s_map
{
	int			higth;
	int			width;
	char		*filename;
	t_data		***data;
	int			zoom;
	void		*mlx_ptr;
	void		*win_ptr;
	int			shift_x;
	int			shift_y;
	int			projection;
}				t_map;

int				ft_exit(t_map *map);
void			parse(t_map *map);
void			draw(t_map *map);
int				hex2int(char *hex);
void			rotation(float *x, float *y, int z);
void			bresenham(float *xy[4], t_map *map, int color);
int				ft_error(const char *str);
int				redraw(int key, t_map *map);
int				ft_exit(t_map *map);

#endif

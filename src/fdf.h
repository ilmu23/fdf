/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:14:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/24 11:01:23 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# ifdef __LINUX__
#  include "mlx.h"
#  include "keys_linux.h"
# endif
# ifndef __LINUX__
#  include <mlx.h>
#  include "keys_macos.h"
# endif

# define E_MAP 1
# define WIDTH 1920
# define HEIGHT 1080

// Constants
# define PI	3.14
# define AXIS_A 20
# define AXIS_B 10

// Colors
# define BGCOLOR 0x00000000

# define FRED 0x00FF0000
# define FGREEN 0x0000FF00
# define FBLUE 0x000000FF

# define MAGENTA 0x00FC1A70
# define PURPLE 0x00AF87FF
# define GREEN 0x00A4E400
# define CYAN 0x0062D8F1

typedef struct s_map
{
	int		**map;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_frame
{
	t_img	*img;
	t_map	*map;
	void	*mlx;
	void	*win;
	char	rotate;
	int		floor;
	int		centerx;
	int		centery;
	int		xoffset;
	int		yoffset;
	double	depth;
	double	vec_ax;
	double	vec_ay;
	double	vec_bx;
	double	vec_by;
	double	zoomlvl;
	double	rotation;
	t_color	color1;
	t_color	color2;
	t_color	ogcolor1;
	t_color	ogcolor2;
}	t_frame;

// map.c
t_map	*parsemap(char *fname);

// color.c
void	updatecolors(t_frame *frame);
void	setcolor(t_color *color, int value);
void	cpycolor(t_color *dst, t_color *src);
int		getnewcolor(int c, int dc, int start, int end);

// rainbow.c
void	rainbow(t_frame *frame, char stop);

// frame.c
int		createframe(t_frame *frame);

// pixel.c
void	drawbackground(t_frame *frame);
void	putpixel(t_frame *frame, int x, int y, int *height);

// actions.c
void	togglefloor(t_frame *frame);
void	togglerotate(t_frame *frame);
void	zoom(t_frame *frame, char direction);
void	rotate(t_frame *frame, char direction);
void	translate(t_frame *frame, char axis, char direction);

#endif

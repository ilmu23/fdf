/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:14:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 13:31:46 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# ifdef LINUX
#  include "mlx.h"
# endif
# ifndef LINUX
#  include <mlx.h>
# endif

# define E_MAP 1
# define PXLPFX "\e[1;36mfdf: putpixel: "
# define WIDTH 1920
# define HEIGHT 1080

// Keycodes
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_Z 6
# define KEY_X 7

// Constants
# define PI	3.14
# define AXIS_A 20
# define AXIS_B 10

// Colors
# define BGCOLOR 0x00000000
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
}	t_frame;

// map.c
t_map	*parsemap(char *fname);

// frame.c
int		createframe(t_frame *frame);

// pixel.c
void	drawbackground(t_img *img);
void	putpixel(t_img *img, int x, int y, int color);

// actions.c
void	togglefloor(t_frame *frame);
void	togglerotate(t_frame *frame);
void	zoom(t_frame *frame, char direction);
void	rotate(t_frame *frame, char direction);
void	translate(t_frame *frame, char axis, char direction);

#endif

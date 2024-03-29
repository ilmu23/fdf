/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:14:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 19:59:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# ifdef __LINUX__
#  include "mlx.h"
#  include "keys_linux.h"
# endif
# ifndef __LINUX__
#  include <mlx.h>
#  include "keys_macos.h"
# endif

# define E_MAP 1
# define E_INIT 2
# define WIDTH 1920
# define HEIGHT 1080

// Output
# define TERM_CLR "\e[1;1H\e[0J"

// Constants
# define PI	3.14
# define AXIS_A 20
# define AXIS_B 10

// Colors
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF

# define PRED 0x00FF0000
# define PGREEN 0x0000FF00
# define PBLUE 0x000000FF

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
	int		end;
}	t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

# ifdef __LINUX__

typedef struct s_frame
{
	t_img	*img;
	t_map	*map;
	void	*mlx;
	void	*win;
	char	floor;
	char	rotate;
	char	colormode;
	long	fpscap;
	int		centerx;
	int		centery;
	int		xoffset;
	int		yoffset;
	int		bgcolor;
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

# endif

# ifndef __LINUX__

typedef struct s_frame
{
	t_img	*img;
	t_map	*map;
	void	*mlx;
	void	*win;
	char	floor;
	char	rotate;
	char	colormode;
	int		centerx;
	int		centery;
	int		xoffset;
	int		yoffset;
	int		bgcolor;
	double	depth;
	double	vec_ax;
	double	vec_ay;
	double	vec_bx;
	double	vec_by;
	double	zoomlvl;
	double	rotation;
	size_t	fpscap;
	t_color	color1;
	t_color	color2;
	t_color	ogcolor1;
	t_color	ogcolor2;
}	t_frame;

# endif

// map.c
t_map	*parsemap(char *fname);

// opt.c
void	printcoloropts(void);
void	printcolormodes(void);
int		checkcoloropt(char *in);

// init.c
void	fdf_init(t_frame *frame, t_img *img);
void	initcolors(t_frame *frame);

// input.c
long	get_fpscap(void);
char	get_floor(void);
char	get_autorotate(void);
int		get_next_color(int n);
int		get_color_value(void);

// input2.c
char	get_colormode(void);

// color.c
void	updatecolors(t_frame *frame, char init);
void	setcolor(t_color *color, int value);
void	cpycolor(t_color *dst, t_color *src);
int		colortohex(t_color *color);
int		getnewcolor(int c, int dc, int start, int end);

// flash.c
void	flashcolor(t_color *color, t_color *end, char stop);

// rainbow.c
void	rainbow(t_frame *frame, char stop);

// frame.c
int		createframe(t_frame *frame);

// pixel.c
void	drawbackground(t_frame *frame);
void	putpixel(t_frame *frame, int x, int y, int *heights);

// actions.c
void	togglefloor(t_frame *frame);
void	togglerotate(t_frame *frame);
void	zoom(t_frame *frame, int keycode);
void	rotate(t_frame *frame, int keycode);
void	translate(t_frame *frame, int keycode);

// actions2.c
void	togglecolormode(t_frame *frame);

#endif

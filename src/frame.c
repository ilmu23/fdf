/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:48:19 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 15:49:08 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	createline(t_frame *frame, size_t x);
static void	calculatepos(t_frame *frame, int off_x, int off_y, int *pos);
static void	drawline(int *pos1, int *pos2, int *heights, t_frame *frame);

int	createframe(t_frame *frame)
{
	size_t	x;
	clock_t	drawtime;
	clock_t	start;
	clock_t	end;

	x = 0;
	frame->xoffset = 0;
	frame->yoffset = 0;
	start = clock();
	drawbackground(frame);
	while (x < frame->map->height)
		createline(frame, x++);
	end = clock();
	drawtime = end - start;
	if (drawtime < CLOCKS_PER_SEC / frame->fpscap)
		usleep(CLOCKS_PER_SEC / frame->fpscap - drawtime);
	mlx_put_image_to_window(frame->mlx, frame->win, frame->img->img, 0, 0);
	return (0);
}

static void	createline(t_frame *frame, size_t x)
{
	size_t	y;
	int		pos1[2];
	int		pos2[2];
	int		heights[2];

	y = 0;
	while (y < frame->map->width)
	{
		calculatepos(frame, x, y, pos1);
		if (y + 1 < frame->map->width)
		{
			calculatepos(frame, x, y + 1, pos2);
			heights[0] = frame->map->map[x][y];
			heights[1] = frame->map->map[x][y + 1];
			drawline(pos1, pos2, (int *)heights, frame);
		}
		if (x + 1 < frame->map->height)
		{
			calculatepos(frame, x + 1, y, pos2);
			heights[0] = frame->map->map[x][y];
			heights[1] = frame->map->map[x + 1][y];
			drawline(pos1, pos2, (int *)heights, frame);
		}
		y++;
	}
}

static void	calculatepos(t_frame *frame, int x, int y, int *pos)
{
	int		**map;
	int		center[2];
	int		xy[2];
	double	depth;
	double	vecs[4];

	xy[0] = x;
	xy[1] = y;
	depth = frame->depth;
	map = frame->map->map;
	vecs[0] = frame->vec_ax;
	vecs[1] = frame->vec_ay;
	vecs[2] = frame->vec_bx;
	vecs[3] = frame->vec_by;
	center[0] = frame->centerx;
	center[1] = frame->centery;
	y -= frame->map->width / 2 + frame->yoffset;
	x -= frame->map->height / 2 + frame->xoffset;
	pos[0] = vecs[0] * x + vecs[2] * y + center[0];
	pos[1] = vecs[1] * x + vecs[3] * y - map[xy[0]][xy[1]] * depth + center[1];
}

static void	drawline(int *pos1, int *pos2, int *heights, t_frame *frame)
{
	double	i;
	double	dx;
	double	dy;
	double	len;
	double	pos[2];

	i = 0;
	dx = (double)pos2[0] - (double)pos1[0];
	dy = (double)pos2[1] - (double)pos1[1];
	len = sqrt((dx * dx) + (dy * dy));
	pos[0] = pos1[0];
	pos[1] = pos1[1];
	while (i < len)
	{
		if (pos[0] >= 0 && pos[0] < WIDTH && pos[1] >= 0 && pos[1] < HEIGHT)
			putpixel(frame, pos[0], pos[1], heights);
		pos[0] += dx / len;
		pos[1] += dy / len;
		i++;
	}
}

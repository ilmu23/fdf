/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:37:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 20:02:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	togglefloor(t_frame *frame)
{
	if (frame->floor)
		frame->floor = 0;
	else
		frame->floor = 1;
}

void	togglerotate(t_frame *frame)
{
	if (frame->rotate)
		frame->rotate = 0;
	else
		frame->rotate = 1;
}

void	zoom(t_frame *frame, int keycode)
{
	if (keycode == KEY_X)
	{
		frame->depth *= 1.2;
		frame->vec_ax *= 1.2;
		frame->vec_ay *= 1.2;
		frame->vec_bx *= 1.2;
		frame->vec_by *= 1.2;
		frame->zoomlvl *= 1.2;
	}
	else
	{
		frame->depth /= 1.2;
		frame->vec_ax /= 1.2;
		frame->vec_ay /= 1.2;
		frame->vec_bx /= 1.2;
		frame->vec_by /= 1.2;
		frame->zoomlvl /= 1.2;
	}
}

void	rotate(t_frame *frame, int keycode)
{
	if (keycode == KEY_E)
		frame->rotation += 1;
	else
		frame->rotation -= 1;
	frame->vec_ax = -1 * AXIS_A * sin(frame->rotation / 180.0 * PI);
	frame->vec_ay = AXIS_B * cos(frame->rotation / 180.0 * PI);
	frame->vec_bx = AXIS_A * cos(frame->rotation / 180.0 * PI);
	frame->vec_by = AXIS_B * sin(frame->rotation / 180.0 * PI);
	frame->vec_ax *= frame->zoomlvl;
	frame->vec_ay *= frame->zoomlvl;
	frame->vec_bx *= frame->zoomlvl;
	frame->vec_by *= frame->zoomlvl;
}

void	translate(t_frame *frame, int keycode)
{
	int	zoomoffset;

	zoomoffset = 10 * frame->zoomlvl;
	if (keycode == KEY_A || keycode == KEY_D)
	{
		if (keycode == KEY_D && frame->centerx < INT_MAX - zoomoffset - 5)
			frame->centerx += zoomoffset + 5;
		else if (frame->centerx > INT_MIN + zoomoffset + 5)
			frame->centerx -= zoomoffset + 5;
	}
	else
	{
		if (keycode == KEY_S && frame->centery < INT_MAX - zoomoffset - 5)
			frame->centery += zoomoffset + 5;
		else if (frame->centery > INT_MIN - zoomoffset - 5)
			frame->centery -= zoomoffset + 5;
	}
}

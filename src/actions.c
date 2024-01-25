/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:37:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 17:30:58 by ivalimak         ###   ########.fr       */
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

void	zoom(t_frame *frame, char direction)
{
	if (direction == '+')
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

void	rotate(t_frame *frame, char direction)
{
	if (direction == '+')
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

void	translate(t_frame *frame, char axis, char direction)
{
	if (axis == 'x')
	{
		if (direction == '+' && frame->centerx < INT_MAX)
			frame->centerx += (10 * frame->zoomlvl) + 5;
		else if (frame->centerx > INT_MIN)
			frame->centerx -= (10 * frame->zoomlvl) + 5;
	}
	else
	{
		if (direction == '+' && frame->centery < INT_MAX)
			frame->centery += (10 * frame->zoomlvl) + 5;
		else if (frame->centery > INT_MIN)
			frame->centery -= (10 * frame->zoomlvl) + 5;
	}
}

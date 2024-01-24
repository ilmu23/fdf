/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:11:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 00:23:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initframe(t_frame *frame)
{
	frame->depth = 2;
	initcolors(frame);
	frame->floor = get_floor();
	frame->fpscap = get_fpscap();
	frame->rotate = get_autorotate();
	frame->zoomlvl = 1.0;
	frame->rotation = 23.0;
	frame->centerx = WIDTH / 2;
	frame->centery = HEIGHT / 2;
	frame->vec_ax = -1 * AXIS_A * sin(frame->rotation / 180.0 * PI);
	frame->vec_ay = AXIS_B * cos(frame->rotation / 180.0 * PI);
	frame->vec_bx = AXIS_A * cos(frame->rotation / 180.0 * PI);
	frame->vec_by = AXIS_B * sin(frame->rotation / 180.0 * PI);
	frame->win = mlx_new_window(frame->mlx, WIDTH, HEIGHT, "fdf");
	drawbackground(frame);
	createframe(frame);
}

void	initcolors(t_frame *frame)
{
	int	color;

	color = get_next_color(1);
	setcolor(&frame->color1, color);
	setcolor(&frame->ogcolor1, color);
	color = get_next_color(2);
	setcolor(&frame->color2, color);
	setcolor(&frame->ogcolor2, color);
	color = get_next_color(3);
	frame->bgcolor = color;
	ft_printf("%s", TERM_CLR);
}

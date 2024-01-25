/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:11:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 15:27:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_frame *frame, t_img *img)
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
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, WIDTH, HEIGHT, "fdf");
	img->img = mlx_new_image(frame->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->end);
	frame->img = img;
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

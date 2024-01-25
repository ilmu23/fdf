/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:58:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 17:56:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	getcolor(t_frame *frame, int *color);

void	drawbackground(t_frame *frame)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
			putpixel(frame, x, y++, NULL);
		x++;
	}
}

void	putpixel(t_frame *frame, int x, int y, int *height)
{
	char	*dst;
	int		color;

	color = frame->bgcolor;
	if (height)
		color = getcolor(frame, height);
	dst = frame->img->addr + (y * frame->img->llen + x * (frame->img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	getcolor(t_frame *frame, int *height)
{
	int		color;
	t_color	color1;
	t_color	color2;

	color = 0;
	color1 = frame->color1;
	color2 = frame->color2;
	if (frame->floor && height[0] == 0 && height[1] == 0)
		return (0 << 24 | color1.r << 16 | color1.g << 8 | color1.b);
	if (!frame->floor && height[0] == height[1])
		return (0 << 24 | color1.r << 16 | color1.g << 8 | color1.b);
	return (0 << 24 | color2.r << 16 | color2.g << 8 | color2.b);
}

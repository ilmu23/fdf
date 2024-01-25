/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1624/01/23 21:43:18 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 17:56:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	updatecolors(t_frame *frame, char init)
{
	static t_color	start;
	static t_color	end;
	static int		dr;
	static int		dg;
	static int		db;

	if (init == 1)
	{
		end = frame->color1;
		start = frame->color2;
		dr = end.r - start.r;
		dg = end.g - start.g;
		db = end.b - start.b;
		frame->color1.r -= dr / 2;
		frame->color1.g -= dg / 2;
		frame->color1.b -= db / 2;
		return ;
	}
	frame->color1.r = getnewcolor(frame->color1.r, dr, start.r, end.r);
	frame->color1.g = getnewcolor(frame->color1.g, dg, start.g, end.g);
	frame->color1.b = getnewcolor(frame->color1.b, db, start.b, end.b);
	frame->color2.r = getnewcolor(frame->color2.r, dr, start.r, end.r);
	frame->color2.g = getnewcolor(frame->color2.g, dg, start.g, end.g);
	frame->color2.b = getnewcolor(frame->color2.b, db, start.b, end.b);
}

void	setcolor(t_color *color, int value)
{
	color->r = value >> 16 & 0xFF;
	color->g = value >> 8 & 0xFF;
	color->b = value & 0xFF;
}

void	cpycolor(t_color *dst, t_color *src)
{
	if (!dst || !src)
		return ;
	dst->r = src->r;
	dst->g = src->g;
	dst->b = src->b;
}

int	colortohex(t_color *color)
{
	return (0 << 24 | color->r << 16 | color->g << 8 | color->b);
}

int	getnewcolor(int c, int dc, int start, int end)
{
	if (dc >= 0)
	{
		if (c < end)
			return (c + dc / 96);
		return (start);
	}
	if (c > end)
		return (c + dc / 96);
	return (start);
}

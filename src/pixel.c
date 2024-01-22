/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:58:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/22 12:30:17 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawbackground(t_img *img)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
			putpixel(img, x, y++, BGCOLOR);
		x++;
	}
}

void	putpixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	ft_debugmsg(PXLPFX, "Putting pixel at %d, %d (#%x)", x, y, color);
	dst = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

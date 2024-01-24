/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:30:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/24 11:02:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rshift(t_color *c1, t_color *c2);
static void	gshift(t_color *c1, t_color *c2);
static void	bshift(t_color *c1, t_color *c2);

void	rainbow(t_frame *frame, char stop)
{
	static void	(*f[3])(t_color *c1, t_color *c2) = {rshift, gshift, bshift};
	static char	init = 0;
	static char	phase;

	if (!init)
	{
		init = 1;
		phase = 1;
		setcolor(&frame->color1, FRED);
		setcolor(&frame->color2, FRED);
	}
	if (stop)
	{
		init = 0;
		cpycolor(&frame->color1, &frame->ogcolor1);
		cpycolor(&frame->color2, &frame->ogcolor2);
		return ;
	}
	if (phase == 0 && frame->color1.r == 255)
		phase = 1;
	else if (phase == 1 && frame->color1.g == 255)
		phase = 2;
	else if (phase == 2 && frame->color1.b == 255)
		phase = 0;
	f[(int)phase](&frame->color1, &frame->color2);
}

static void	rshift(t_color *c1, t_color *c2)
{
	c1->r += 1;
	c2->r += 1;
	c1->b -= 1;
	c2->b -= 1;
}

static void	gshift(t_color *c1, t_color *c2)
{
	c1->g += 1;
	c2->g += 1;
	c1->r -= 1;
	c2->r -= 1;
}

static void	bshift(t_color *c1, t_color *c2)
{
	c1->b += 1;
	c2->b += 1;
	c1->g -= 1;
	c2->g -= 1;
}

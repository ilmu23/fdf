/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:32:18 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 23:40:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	togglecolormode(t_frame *frame)
{
	if (frame->colormode == 1)
	{
		cpycolor(&frame->color1, &frame->ogcolor1);
		flashcolor(NULL, NULL, 1);
	}
	else if (frame->colormode == 2)
	{
		cpycolor(&frame->color2, &frame->ogcolor2);
		flashcolor(NULL, NULL, 1);
		updatecolors(frame, 1);
	}
	else if (frame->colormode == 3)
	{
		cpycolor(&frame->color1, &frame->ogcolor1);
		cpycolor(&frame->color2, &frame->ogcolor2);
	}
	else if (frame->colormode == 4)
	{
		cpycolor(&frame->color1, &frame->ogcolor1);
		cpycolor(&frame->color2, &frame->ogcolor2);
		rainbow(NULL, 1);
	}
	frame->colormode++;
	if (frame->colormode > 4)
		frame->colormode = 0;
}

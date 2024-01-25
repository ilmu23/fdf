/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:32:18 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 17:53:57 by ivalimak         ###   ########.fr       */
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
	if (frame->colormode < 4)
		frame->colormode++;
	else
		frame->colormode = 0;
}

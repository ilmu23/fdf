/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:58:32 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 19:27:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	flash(int c, int dc, int start, int end);

void	flashcolor(t_color *color, t_color *start, char stop)
{
	const t_color	end = {0, 0, 0};
	static char		init = 0;
	static int		dr;
	static int		dg;
	static int		db;

	if (!init)
	{
		init = 1;
		dr = color->r;
		dg = color->g;
		db = color->b;
	}
	if (stop)
	{
		init = 0;
		return ;
	}
	color->r = flash(color->r, dr, start->r, end.r);
	color->g = flash(color->g, dg, start->g, end.g);
	color->b = flash(color->b, db, start->b, end.b);
}

static int	flash(int c, int dc, int start, int end)
{
	if (c > end)
		return (c - dc / 64);
	return (start);
}

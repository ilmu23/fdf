/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:19:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 17:29:55 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	get_colormode(void)
{
	char	c;

	ft_printf("%sSet initial color mode\n\n", TERM_CLR);
	printcolormodes();
	c = ft_atoi(get_next_line(1));
	ft_printf("%s", TERM_CLR);
	if (c < 0 || c > 5)
		return (get_colormode());
	return (c);
}

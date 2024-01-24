/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:02:24 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/24 23:12:22 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 */

#include "libft.h"

/** @brief Converts s to an integer value, interpreted as hex
 *
 * @param *s String to convert
 * @retval int Converted value of s
 */
int	ft_atox(const char *s)
{
	long	out;
	int		n;

	n = 1;
	out = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		n = -n;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s) || (ft_toupper(*s) >= 'A' && ft_toupper(*s) <= 'F'))
	{
		if (out > LONG_MAX / 10 || (out == LONG_MAX / 10 && *s > '7'))
		{
			if (n < 0)
				return (0);
			return (1);
		}
		if (ft_isdigit(*s))
			out = out * 16 + (*s++ - '0');
		else
			out = out * 16 + (*s++ - '7');
	}
	return (out * n);
}

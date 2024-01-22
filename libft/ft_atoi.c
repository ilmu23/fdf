/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:50:28 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/11 20:22:57 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 */

#include "libft.h"

/** @brief Converts s to an integer value
 *
 * @param *s String to convert
 * @retval int Converted value of s
 */
int	ft_atoi(const char *s)
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
	while (ft_isdigit(*s))
	{
		if (out > LONG_MAX / 10 || (out == LONG_MAX / 10 && *s > '7'))
		{
			if (n < 0)
				return (0);
			return (1);
		}
		out = out * 10 + (*s - '0');
		s++;
	}
	return (out * n);
}

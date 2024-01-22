/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:18:38 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/11 20:25:12 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atos.c
 */

#include "libft.h"

/** @brief Converts the string s to a size_t value
 *
 * @param *s String to convert
 * @retval size_t Converted value of s
 */
size_t	ft_atos(const char *s)
{
	size_t	out;

	out = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	while (ft_isdigit(*s))
		out = out * 10 + (*s++ - '0');
	return (out);
}

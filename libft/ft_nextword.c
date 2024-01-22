/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:47:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/19 18:49:53 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nextword(const char *s)
{
	while (!ft_isspace(*s))
		s++;
	while (ft_isspace(*s))
		s++;
	if (*s)
		return ((char *)s);
	return (NULL);
}

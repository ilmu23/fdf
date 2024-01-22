/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:46:35 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/11 19:50:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_wordcount.c
 */

#include "libft.h"

/** @brief Counts all the words in string s
 *
 * @param *s String to count the words in
 * @retval size_t Amount of words in s, or 0 if s is NULL
 */
size_t	ft_wordcount(const char *s)
{
	size_t	words;

	if (!s)
		return (0);
	words = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		while (*s && !ft_isspace(*s))
			s++;
		if (*s || !ft_isspace(*(s - 1)))
			words++;
	}
	return (words);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:46:05 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 00:31:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	get_fpscap(void)
{
	char	*line;
	size_t	cap;

	ft_printf("%sSet FPS cap (0 for no cap) > ", TERM_CLR);
	line = ft_strtrim(get_next_line(1), "\n");
	ft_printf("%s", TERM_CLR);
	if (!line)
	{
		perror("fdf");
		ft_exit(E_INIT);
	}
	if (!*line)
		return (60);
	cap = ft_atol(line);
	if (cap < 1)
		return (LONG_MAX);
	return (cap);
}

char	get_floor(void)
{
	char	*line;

	ft_printf("%sUse flat color only for height 0? [Y/n] ", TERM_CLR);
	line = get_next_line(1);
	ft_printf("%s", TERM_CLR);
	if (ft_toupper(*line) == 'Y' || *line == '\n')
		return (1);
	if (ft_toupper(*line) == 'N')
		return (0);
	return (get_floor());
}

char	get_autorotate(void)
{
	char	*line;

	ft_printf("%sEnable automatic rotation? [Y/n] ", TERM_CLR);
	line = get_next_line(1);
	ft_printf("%s", TERM_CLR);
	if (ft_toupper(*line) == 'Y' || *line == '\n')
		return (1);
	if (ft_toupper(*line) == 'N')
		return (0);
	return (get_autorotate());
}

int	get_next_color(int n)
{
	char	*line;
	int		color;

	if (n == 1)
		ft_printf("%sSelect flat color\n\n", TERM_CLR);
	else if (n == 2)
		ft_printf("%sSelect slope color\n\n", TERM_CLR);
	else
		ft_printf("%sSelect background color\n\n", TERM_CLR);
	printcoloropts();
	line = ft_strtrim(ft_strupper(get_next_line(0)), "\n");
	if (!line)
	{
		perror("fdf");
		ft_exit(E_INIT);
	}
	if (!ft_strncmp(line, "BLACK", 6))
		return (0);
	color = checkcoloropt(line);
	if (!color)
		get_next_color(n);
	return (color);
}

int	get_color_value(void)
{
	char	*value;

	ft_printf("%sEnter value\n\n> ", TERM_CLR);
	value = ft_strtrim(ft_strupper(get_next_line(1)), "\n");
	if (ft_strlen(value) != 6)
		return (0);
	return (ft_atox(value));
}

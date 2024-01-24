/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:11:14 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/24 23:27:00 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	checkinput(char *in);
static int	get_next_color(int n);
static int	get_color_value(void);

void	initcolors(t_frame *frame)
{
	int	color;

	color = get_next_color(1);
	setcolor(&frame->color1, color);
	setcolor(&frame->ogcolor1, color);
	color = get_next_color(2);
	setcolor(&frame->color2, color);
	setcolor(&frame->ogcolor2, color);
	color = get_next_color(3);
	frame->bgcolor = color;
	ft_printf("%s", TERM_CLR);
}

static void	printcolors(void)
{
	ft_printf("  BLACK        [OOOOOO]\n");
	ft_printf("  WHITE        [FFFFFF]\n");
	ft_printf("  PURE RED     [FF0000]\n");
	ft_printf("  PURE GREEN   [00FF00]\n");
	ft_printf("  PURE BLUE    [0000FF]\n");
	ft_printf("  MAGENTA      [FC1A70]\n");
	ft_printf("  PURPLE       [AF87FF]\n");
	ft_printf("  GREEN        [A4E400]\n");
	ft_printf("  CYAN         [62D8F1]\n");
	ft_printf("  CUSTOM       [??????]\n");
	ft_printf("\n> ");
}

static int	checkinput(char *in)
{
	if (!ft_strncmp(in, "BLACK", 6))
		return (BLACK);
	if (!ft_strncmp(in, "WHITE", 6))
		return (WHITE);
	if (!ft_strncmp(in, "PURE RED", 9))
		return (PRED);
	if (!ft_strncmp(in, "PURE GREEN", 11))
		return (PGREEN);
	if (!ft_strncmp(in, "PURE BLUE", 10))
		return (PBLUE);
	if (!ft_strncmp(in, "MAGENTA", 8))
		return (MAGENTA);
	if (!ft_strncmp(in, "PURPLE", 7))
		return (PURPLE);
	if (!ft_strncmp(in, "GREEN", 6))
		return (GREEN);
	if (!ft_strncmp(in, "CYAN", 5))
		return (CYAN);
	if (!ft_strncmp(in, "CUSTOM", 7))
		return (get_color_value());
	return (0);
}

static int	get_next_color(int n)
{
	char	*line;
	int		color;

	if (n == 1)
		ft_printf("%sSelect flat color\n\n", TERM_CLR);
	else if (n == 2)
		ft_printf("%sSelect slope color\n\n", TERM_CLR);
	else
		ft_printf("%sSelect background color\n\n", TERM_CLR);
	printcolors();
	line = ft_strtrim(ft_strupper(get_next_line(0)), "\n");
	if (!ft_strncmp(line, "BLACK", 6))
		return (0);
	color = checkinput(line);
	if (!color)
		get_next_color(n);
	return (color);
}

static int	get_color_value(void)
{
	char	*value;

	ft_printf("%sEnter value\n\n> ", TERM_CLR);
	value = ft_strtrim(ft_strupper(get_next_line(1)), "\n");
	if (ft_strlen(value) != 6)
		return (0);
	return (ft_atox(value));
}

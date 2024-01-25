/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:51:39 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 17:54:45 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printcoloropts(void)
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

void	printcolormodes(void)
{
	ft_printf("  Static colors        (0)\n");
	ft_printf("  Flash flat color     (1)\n");
	ft_printf("  Flash slope color    (2)\n");
	ft_printf("  Cycle between colors (3)\n");
	ft_printf("  Rainbow              (4)\n");
	ft_printf("\n> ");
}

int	checkcoloropt(char *in)
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

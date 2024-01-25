/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:12:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/25 23:44:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	redraw(int keycode, void *param);
static int	autoupdate(void *param);
static int	quit(t_frame *frame);

int	main(int argc, char **argv)
{
	t_frame	frame;
	t_img	img;

	if (argc != 2)
		return (1);
	frame.map = parsemap(argv[1]);
	if (!frame.map)
	{
		perror("fdf");
		return (ft_return(E_MAP));
	}
	fdf_init(&frame, &img);
	mlx_hook(frame.win, 2, (1L << 0), redraw, &frame);
	mlx_hook(frame.win, 17, (1L << 0), quit, &frame);
	mlx_loop_hook(frame.mlx, autoupdate, &frame);
	mlx_loop(frame.mlx);
}

static int	redraw(int keycode, void *param)
{
	if (keycode == KEY_E || keycode == KEY_Q)
		rotate(param, keycode);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		translate(param, keycode);
	else if (keycode == KEY_Z || keycode == KEY_X)
		zoom(param, keycode);
	else if (keycode == KEY_R)
		togglerotate(param);
	else if (keycode == KEY_F)
		togglefloor(param);
	else if (keycode == KEY_C)
		togglecolormode(param);
	else if (keycode == KEY_ESC)
		quit(param);
	createframe(param);
	return (1);
}

static int	autoupdate(void *param)
{
	t_frame	*frame;
	char	updates;

	frame = param;
	updates = 0;
	if (frame->rotate)
	{
		rotate(param, KEY_E);
		updates++;
	}
	if (frame->colormode)
	{
		if (frame->colormode == 1)
			flashcolor(&frame->color1, &frame->ogcolor1, 0);
		else if (frame->colormode == 2)
			flashcolor(&frame->color2, &frame->ogcolor2, 0);
		else if (frame->colormode == 3)
			updatecolors(frame, 0);
		else
			rainbow(frame, 0);
		updates++;
	}
	if (updates)
		createframe(frame);
	return (1);
}

static int	quit(t_frame *frame)
{
	mlx_destroy_window(frame->mlx, frame->win);
	ft_exit(0);
	return (0);
}

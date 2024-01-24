/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:12:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/24 18:18:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initframe(t_frame *frame);
static int	redraw(int keycode, void *param);
static int	autorotate(void *param);
static int	quit(t_frame *frame);

int	main(int argc, char **argv)
{
	t_frame	frame;
	t_img	img;

	if (argc < 2)
		return (1);
	frame.map = parsemap(argv[1]);
	if (!frame.map)
	{
		perror("fdf");
		return (ft_return(E_MAP));
	}
	frame.floor = 0;
	if (argc > 2)
		frame.floor = ft_atoi(argv[2]);
	frame.mlx = mlx_init();
	frame.win = mlx_new_window(frame.mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(frame.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.llen, &img.endian);
	frame.img = &img;
	initframe(&frame);
	mlx_hook(frame.win, 2, (1L << 0), redraw, &frame);
	mlx_hook(frame.win, 17, (1L << 0), quit, &frame);
	mlx_loop_hook(frame.mlx, autorotate, &frame);
	mlx_loop(frame.mlx);
}

static void	initframe(t_frame *frame)
{
	frame->depth = 2;
	frame->rotate = 0;
	frame->zoomlvl = 1.0;
	frame->rotation = 23.0;
	frame->centerx = WIDTH / 2;
	frame->centery = HEIGHT / 2;
	setcolor(&frame->color1, PURPLE);
	setcolor(&frame->ogcolor1, PURPLE);
	setcolor(&frame->color2, MAGENTA);
	setcolor(&frame->ogcolor2, MAGENTA);
	frame->vec_ax = -1 * AXIS_A * sin(frame->rotation / 180.0 * PI);
	frame->vec_ay = AXIS_B * cos(frame->rotation / 180.0 * PI);
	frame->vec_bx = AXIS_A * cos(frame->rotation / 180.0 * PI);
	frame->vec_by = AXIS_B * sin(frame->rotation / 180.0 * PI);
	createframe(frame);
}

static int	redraw(int keycode, void *param)
{
	if (keycode == KEY_E)
		rotate(param, '+');
	else if (keycode == KEY_Q)
		rotate(param, '-');
	else if (keycode == KEY_W)
		translate(param, 'y', '-');
	else if (keycode == KEY_A)
		translate(param, 'x', '-');
	else if (keycode == KEY_S)
		translate(param, 'y', '+');
	else if (keycode == KEY_D)
		translate(param, 'x', '+');
	else if (keycode == KEY_Z)
		zoom(param, '-');
	else if (keycode == KEY_X)
		zoom(param, '+');
	else if (keycode == KEY_R)
		togglerotate(param);
	else if (keycode == KEY_F)
		togglefloor(param);
	else if (keycode == KEY_ESC)
		quit(param);
	drawbackground(param);
	createframe(param);
	return (1);
}

static int	autorotate(void *param)
{
	if (((t_frame *)param)->rotate)
	{
		rotate(param, '+');
		if (((t_frame *)param)->rotate == 2 || ((t_frame *)param)->rotate == 3)
			updatecolors(param);
		else if (((t_frame *)param)->rotate == 4)
			rainbow(param, 0);
		drawbackground(param);
		createframe(param);
	}
	return (1);
}

static int	quit(t_frame *frame)
{
	mlx_destroy_window(frame->mlx, frame->win);
	ft_exit(0);
	return (0);
}

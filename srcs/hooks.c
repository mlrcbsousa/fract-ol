/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:01:20 by msousa            #+#    #+#             */
/*   Updated: 2021/11/08 12:00:59 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int close_app(t_app *self)
{
	mlx_destroy_window(self->mlx, self->mlx_window);
	exit(0);
}

#include <stdio.h>

static void move(int key, t_app *self)
{
	double size;

	// printf("move: %d\n", key);

	if (key == ARROW_RIGHT || key == ARROW_LEFT)
	{
		size = range_size(self->axis_x);
		self->axis_x = range_move(self->axis_x,
															size * 0.05 * ft_ternary(key == ARROW_RIGHT,
																											 1, -1));
	}
	else if (key == ARROW_UP || key == ARROW_DOWN)
	{
		size = range_size(self->axis_y);
		self->axis_y = range_move(self->axis_y,
															size * 0.05 * ft_ternary(key == ARROW_DOWN,
																											 1, -1));
	}
	draw(self);
}

static int key_hook(int key, t_app *self)
{
	if (key == KEY_ESC)
		close_app(self);
	else if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_LEFT ||
					 key == ARROW_RIGHT)
		move(key, self);
	else if (key == KEY_C)
	{
		self->shift = (self->shift + 1) % 3;
		draw(self);
	}
	return (0);
}

// change
static double interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static int zoom(int button, int x, int y, t_app *self)
{
	t_point mouse;
	double ratio;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		mouse = (t_point){
				(double)x / (WIDTH / (self->axis_x.min - self->axis_y.min)) + self->axis_x.min,
				(double)y / (HEIGHT / (self->axis_x.max - self->axis_y.max)) * -1 + self->axis_x.max};
		if (button == SCROLL_UP)
			ratio = 1.0 / 0.80;
		else
			ratio = 1.0 / 1.20;
		// self->axis_x = range_resize(self->axis_x, ratio);
		// self->axis_y = range_resize(self->axis_y, ratio);

		self->axis_x.min = interpolate(mouse.x, self->axis_x.min, ratio);
		self->axis_x.max = interpolate(mouse.x, self->axis_x.max, ratio);

		self->axis_y.min = interpolate(mouse.y, self->axis_y.min, ratio);
		self->axis_y.max = interpolate(mouse.y, self->axis_y.max, ratio);
		draw(self);
	}
	return (0);
}

void set_hooks(t_app *self)
{
	mlx_key_hook(self->mlx_window, key_hook, self);
	mlx_hook(self->mlx_window, BUTTON_PRESS, 0, zoom, self);
	mlx_hook(self->mlx_window, DESTROY_NOTIFY, 0, close_app, self);
}

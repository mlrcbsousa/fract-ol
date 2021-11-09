/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:01:20 by msousa            #+#    #+#             */
/*   Updated: 2021/11/09 22:29:56 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_app(t_app *self)
{
	mlx_destroy_window(self->mlx, self->mlx_window);
	exit(0);
}

static void	move(int key, t_app *self)
{
	if (key == ARROW_RIGHT || key == ARROW_LEFT)
		self->axis_x = range_move(self->axis_x,
				range_size(self->axis_x) * 0.05
				* ft_ternary(key == ARROW_RIGHT, 1, -1));
	else if (key == ARROW_UP || key == ARROW_DOWN)
		self->axis_y = range_move(self->axis_y,
				range_size(self->axis_y) * 0.05
				* ft_ternary(key == ARROW_DOWN, 1, -1));
	draw(self);
}

static int	key_hook(int key, t_app *self)
{
	if (key == KEY_ESC)
		close_app(self);
	else if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_LEFT
		|| key == ARROW_RIGHT)
		move(key, self);
	else if (key == KEY_C)
	{
		self->shift = (self->shift + 1) % 3;
		draw(self);
	}
	return (0);
}

static int	zoom(int button, int x, int y, t_app *self)
{
	double	ratio;
	double	x_mapped;
	double	y_mapped;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		if (button == SCROLL_UP)
			ratio = 1.0 / 1.5;
		else
			ratio = 1.0 / 0.5;
		x_mapped = range_map(x, WINDOW_X, self->axis_x);
		y_mapped = range_map(y, WINDOW_Y, self->axis_y);
		self->axis_x = range_move(self->axis_x, -x_mapped);
		self->axis_y = range_move(self->axis_y, -y_mapped);
		self->axis_x = range_resize(self->axis_x, ratio);
		self->axis_y = range_resize(self->axis_y, ratio);
		self->axis_x = range_move(self->axis_x, x_mapped);
		self->axis_y = range_move(self->axis_y, y_mapped);
		draw(self);
	}
	return (0);
}

void	set_hooks(t_app *self)
{
	mlx_key_hook(self->mlx_window, key_hook, self);
	mlx_hook(self->mlx_window, BUTTON_PRESS, 1L<<2, zoom, self);
	mlx_hook(self->mlx_window, DESTROY_NOTIFY, 0, close_app, self);
}

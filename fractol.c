/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:00:32 by msousa            #+#    #+#             */
/*   Updated: 2021/11/05 11:51:20 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iterations, t_app *self)
{
	double	ratio;
	int	rgb[3];

	ratio = sqrt((double)iterations / (double)MAX_ITERATIONS);
	rgb[(0 + self->shift) % 3] =
		(15 * pow((1 - ratio), 2) * pow(ratio, 2) * 255);
	rgb[(1 + self->shift) % 3] =
		(9 * pow((1 - ratio), 1) * pow(ratio, 3) * 255);
	rgb[(2 + self->shift) % 3] =
		(8.5 * pow((1 - ratio), 3) * pow(ratio, 1) * 255);

	if (iterations == MAX_ITERATIONS)
		return (create_trgb(0, 0, 0, 0));
	return (create_trgb(0, rgb[0], rgb[1], rgb[2]));
}

void draw(t_app *self)
{
	int i;
	int j;
	int iterations;
	int color;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			iterations = self->fractal.formula(i, j, self);
			color = get_color(iterations, self);
			my_mlx_pixel_put(self->img, i, HEIGHT - j - 1, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(self->mlx, self->mlx_window, self->img->img, 0, 0);
}

static t_bool	set_fractal(char *argv, t_app *self)
{
	static t_fractal	fractals[2] = {
		{ "Mandelbrot", mandelbrot },
		{ "Julia", julia },
	};
	int	i;

	i = 0;
	while (i < 2)
	{
		if (ft_streq(argv, fractals[i].name))
		{
			self->fractal = fractals[i];
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static t_bool	invalid(int argc, char* argv[], t_app *self)
{
	if (argc < 2 || !set_fractal(argv[1], self))
		return (TRUE);
	if (ft_streq(argv[1], "Julia") &&
			(argc < 4 || (argv[2] && !ft_isfloat(argv[2])) ||
				(argv[3] && !ft_isfloat(argv[3]))))
		return (TRUE);
	return (FALSE);
}

#include <stdio.h>

void set_image(t_app *self)
{
	t_image *img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
	{
		ft_putendl_fd("Failed to allocate image memory!", 2);
		exit(1);
	}
	img->img = mlx_new_image(self->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img,
																&(img->bits_per_pixel),
																&(img->line_length),
															 	&(img->endian));
	self->img = img;
}

int ft_indexofi(int *array, int size, int n)
{
	int	i;

	i = 0;
	while (size > i)
		if (*(array + sizeof(int)) == n)
			return (i);
		i++;
	return (-1);
}

t_bool ft_includesi(int *array, int size, int n)
{
	return (ft_indexofi(array, size, n) != -1);
}

void move(int key, t_app *self)
{
	double	size;

	printf("move: %d\n", key);

	if (key == ARROW_RIGHT || key == ARROW_LEFT)
	{
		size = range_size(self->axis_x);
		if (key == ARROW_RIGHT)
			self->axis_x = range_move(self->axis_x, size * 0.05);
		else
			self->axis_x = range_move(self->axis_x, size * -0.05);
	}
	else if (key == ARROW_UP || key == ARROW_DOWN)
	{
		size = range_size(self->axis_y);
		if (key == ARROW_UP)
			self->axis_y = range_move(self->axis_y, size * 0.05);
		else
			self->axis_y = range_move(self->axis_y, size * -0.05);
	}
	draw(self);
}

static void shift_color(t_app *self)
{
	self->shift = (self->shift + 1) % 3;
	draw(self);
}

int close_app(t_app *self)
{
	mlx_destroy_window(self->mlx, self->mlx_window);
	exit(0);
}

int key_hook(int key, t_app *self)
{
	int arrow_keys[4];

	arrow_keys[0] = ARROW_UP;
	arrow_keys[1] = ARROW_DOWN;
	arrow_keys[2] = ARROW_LEFT;
	arrow_keys[3] = ARROW_RIGHT;
	printf("key_hook: %d\n", key);

	printf("%d\n", ft_indexofi(arrow_keys, 4, key));
	if (key == 259)
		return (0);
	if (key == KEY_ESC)
		close_app(self);
	else if (ft_includesi(arrow_keys, 4, key))
		move(key, self);
	else if (key == KEY_C)
		shift_color(self);
	return (0);
}

int button_hook(int keycode, t_app *self)
{
	(void)self;
	printf("button: %d\n", keycode);
	return (0);
}

void	set_hooks(t_app *self)
{
	mlx_hook(self->mlx_window, KEY_PRESS, KEY_PRESS_MASK, key_hook, self);
	// mlx_key_hook(self->mlx_window, key_hook, self);
	mlx_hook(self->mlx_window, BUTTON_PRESS, 0, button_hook, self);
	mlx_hook(self->mlx_window, 17, 0, close_app, self);
}

int	main(int argc, char *argv[])
{
	t_app	self;

	self = (t_app){
		.axis_x = (t_range){ -2 * RATIO, 2 * RATIO },
		.axis_y = (t_range){ -2, 2 },
	};

	if (invalid(argc, argv, &self))
		usage();
	else
	{
		if (ft_streq(argv[1], "Julia"))
			self.c = (t_point) { ft_atof(argv[2]), ft_atof(argv[3]) };

		self.mlx = mlx_init();

		self.mlx_window = mlx_new_window(self.mlx, WIDTH, HEIGHT, self.fractal.name);
		set_image(&self);
		set_hooks(&self);
		draw(&self);

		mlx_loop(self.mlx);
	}

	return (0);
}

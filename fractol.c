/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:00:32 by msousa            #+#    #+#             */
/*   Updated: 2021/11/04 23:25:40 by msousa           ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	void *mlx;
	void *mlx_win;
	t_image img;
	t_app	self;

	self = (t_app){
		.axis_x = (t_range){ -2 * RATIO, 2 * RATIO },
		.axis_y = (t_range){ -2, 2 },
	};
	
	// ft_printf("!invalid: %d\n", !invalid(argc, argv, &self));
	if (invalid(argc, argv, &self))
		usage();
	else
	{
		// printf("ft_atod: %lf %lf\n", ft_atod(argv[2]), ft_atod(argv[3]));
		ft_atod(argv[2]);
		ft_atod(argv[3]);
		if (ft_streq(argv[1], "Julia"))
			self.c = (t_point){ -0.835, -0.2321 };
		// 	self.c = (t_point) { ft_atod(argv[2]), ft_atod(argv[3]) };
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, self.fractal.name);
		img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
																&img.endian);
		self.img = &img;
		draw(&self);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}	
	
	return (0);
}

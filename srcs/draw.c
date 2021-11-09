/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:06:29 by msousa            #+#    #+#             */
/*   Updated: 2021/11/09 21:50:20 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int generate_rgb(double ratio, int power, double n)
{
	return (n * pow((1 - ratio), power) * pow(ratio, (4 - power)) * 255);
}

static int get_color(int iterations, t_app *self)
{
	double ratio;
	int rgb[3];

	if (iterations == MAX_ITERATIONS)
		return (create_trgb(0, 0, 0, 0));
	ratio = sqrt((double)iterations / (double)MAX_ITERATIONS);
	rgb[(0 + self->shift) % 3] = generate_rgb(ratio, 2, 15);
	rgb[(1 + self->shift) % 3] = generate_rgb(ratio, 1, 9);
	rgb[(2 + self->shift) % 3] = generate_rgb(ratio, 3, 8.5);
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
			my_mlx_pixel_put(self->img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(self->mlx, self->mlx_window, self->img->img, 0, 0);
}

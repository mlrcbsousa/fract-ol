/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:00:32 by msousa            #+#    #+#             */
/*   Updated: 2021/11/03 16:15:33 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(int i, int j)
{
	int iterations;
	t_point z;
	t_point c;

	t_range	window_x;
	t_range window_y;
	t_range	axis_x;
	t_range	axis_y;
	double	ratio;

	window_x = (t_range){.min = 0.0, .max = (double)WIDTH};
	window_y = (t_range){.min = 0.0, .max = (double)HEIGHT};
	ratio = window_x.max / window_y.max;
	axis_x = (t_range){.min = -2.0 * ratio, .max = 2.0 * ratio};
	axis_y = (t_range){.min = -2.0, .max = 2.0};

	iterations = 0;
	z = (t_point){.x = 0.0, .y = 0.0};
	c = (t_point){
			.x = range_map(i, window_x, axis_x),
			.y = range_map(j, window_y, axis_y)};

	while (iterations <= MAX_ITERATIONS && z.x <= 2.0 && z.y <= 2.0)
	{
		z = point_add(complex_squared(z), c);
		iterations++;
	}
	return (iterations);
}

void draw(t_image *img)
{
	int i;
	int j;
	int iterations;
	int color;
	int rgb;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			iterations = mandelbrot(i, j);
			rgb = sqrt((double)iterations / (double)MAX_ITERATIONS) * (double)255;
			color = create_trgb(0, rgb, rgb, rgb);
			my_mlx_pixel_put(img, i, HEIGHT - j, color);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void *mlx;
	void *mlx_win;
	t_image img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
															 &img.endian);
	draw(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	return (0);
}

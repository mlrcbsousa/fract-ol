/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:00:32 by msousa            #+#    #+#             */
/*   Updated: 2021/11/04 15:14:06 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int julia(int i, int j, t_point c)
// {
// 	int iterations;
// 	t_point z;
// 	t_point c;

// 	t_range window_x;
// 	t_range window_y;
// 	t_range axis_x;
// 	t_range axis_y;
// 	double ratio;

// 	window_x = (t_range){.min = 0.0, .max = (double)WIDTH};
// 	window_y = (t_range){.min = 0.0, .max = (double)HEIGHT};
// 	ratio = window_x.max / window_y.max;
// 	axis_x = (t_range){.min = -2.5 * ratio, .max = 2.5 * ratio};
// 	axis_y = (t_range){.min = -2.5, .max = 2.5};

// 	iterations = 0;
// 	z = (t_point){.x = 0.0, .y = 0.0};
// 	c = (t_point){
// 			.x = range_map(i, window_x, axis_x),
// 			.y = range_map(j, window_y, axis_y)};

// 	while (iterations < MAX_ITERATIONS)
// 	{
// 		if (z.x * z.x + z.y * z.y > 16.0)
// 			break;
// 		z = point_add(complex_squared(z), c);
// 		iterations++;
// 	}
// 	return (iterations);
// }

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
	axis_x = (t_range){.min = -2 * ratio, .max = 2 * ratio};
	axis_y = (t_range){.min = -2, .max = 2};

	iterations = 0;
	z = (t_point){.x = 0.0, .y = 0.0};
	c = (t_point){
			.x = range_map(i, window_x, axis_x),
			.y = range_map(j, window_y, axis_y)};

	// c = (t_point) { .x = -0.835, .y = -0.2321 };
	// z = (t_point){
	// 		.x = range_map(i, window_x, axis_x),
	// 		.y = range_map(j, window_y, axis_y)};

	while (iterations < MAX_ITERATIONS)
	{
		if (pow(z.x, 4.0) + pow(z.y, 4.0) > 16.0)
			break;
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
	// int rgb;

	double	ratio;
	int red;
	int green;
	int blue;
	// int shift;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			iterations = mandelbrot(i, j);
			ratio = sqrt((double)iterations / (double)MAX_ITERATIONS);

			// rgb = sqrt((double)iterations / (double)MAX_ITERATIONS) * 255.0;
			// rgb = (double)iterations / (double)MAX_ITERATIONS * 255.0;
			red = (9 * (1 - ratio) * pow(ratio, 3) * 255);
			green = (15 * pow((1 - ratio), 2) * pow(ratio, 2) * 255);
			blue = (8.5 * pow((1 - ratio), 3) * ratio * 255);

			if (iterations == MAX_ITERATIONS)
			{
				red = 0;
				green = 0;
				blue = 0;
			}
			color = create_trgb(0, red, green, blue);
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

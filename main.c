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
		if (pow(z.x, 2.0) + pow(z.y, 2.0) > 4.0)
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
			red = (15 * pow((1 - ratio), 2) * pow(ratio, 2) * 255);
			green = (9 * pow((1 - ratio), 1) * pow(ratio, 3) * 255);
			blue = (8.5 * pow((1 - ratio), 3) * pow(ratio, 1) * 255);

			if (iterations == MAX_ITERATIONS)
			{
				red = 0;
				green = 0;
				blue = 0;
			}
			color = create_trgb(0, red, green, blue);
			my_mlx_pixel_put(img, i, HEIGHT - j - 1, color);
			j++;
		}
		i++;
	}
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	usage(void)
{
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("Usage: ./fractol <name> <a> <b>", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("   - name   Name of fractal to display", 1);
	ft_putendl_fd("            options: Mandelbrot", 1);
	ft_putendl_fd("                     Julia", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("   - a      Only if fractal choice is Julia", 1);
	ft_putendl_fd("            real component of constant C", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("   - b      Only if fractal choice is Julia", 1);
	ft_putendl_fd("            imaginary component of constant C", 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char *argv[])
{
	void *mlx;
	void *mlx_win;
	t_image img;

	(void)argv;
	if (argc < 2)
	{
		usage();
		exit(0);
	}
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

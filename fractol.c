/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:00:32 by msousa            #+#    #+#             */
/*   Updated: 2021/11/09 19:30:40 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_bool	set_fractal(char *argv, t_app *self)
{
	static t_fractal fractals[3] = {
			{"Mandelbrot", mandelbrot},
			{"Julia", julia},
			{"Burning Ship", burning_ship},
	};
	int	i;

	i = 0;
	while (i < (int)(sizeof(fractals) / sizeof(t_fractal)))
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

static void set_image(t_app *self)
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

static void usage(void)
{
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("Usage: ./fractol <name> <a> <b>", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("   - name   Name of fractal to display", 1);
	ft_putendl_fd("            options: Mandelbrot", 1);
	ft_putendl_fd("                     Julia", 1);
	ft_putendl_fd("                     Burning Ship", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("   - a      Only if fractal choice is Julia", 1);
	ft_putendl_fd("            real component of constant C", 1);
	ft_putendl_fd("            double in the form (-)0.0", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("   - b      Only if fractal choice is Julia", 1);
	ft_putendl_fd("            imaginary component of constant C", 1);
	ft_putendl_fd("            double in the form (-)0.0", 1);
	ft_putendl_fd(NULL, 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_app	self;

	if (invalid(argc, argv, &self))
		usage();
	else
	{
		self.axis_x = (t_range){-2.0 * RATIO, 2.0 * RATIO};
		self.axis_y = (t_range){-2.0, 2.0};
		self.shift = 0;
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

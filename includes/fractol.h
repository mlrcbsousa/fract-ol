/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:34 by msousa            #+#    #+#             */
/*   Updated: 2021/11/04 22:36:21 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_boolean.h"
# include "ft_point.h"
# include "ft_range.h"
# include "ft_mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define RATIO ((double)WIDTH / (double)HEIGHT)
# define MAX_ITERATIONS 100

# define WINDOW_X ((t_range){ 0.0, WIDTH })
# define WINDOW_Y ((t_range){ 0.0, HEIGHT })

typedef struct s_app	t_app;
typedef int	(*t_formula)(int, int, t_app*);
typedef struct s_fractal	t_fractal;

struct	s_fractal
{
	char	*name;
	t_formula formula;
};

struct	s_app
{
	t_range	axis_x;
	t_range	axis_y;
	t_fractal	fractal;
	t_point	c;
	t_image	*img;
	int	shift;
};

// Formulas
int mandelbrot(int i, int j, t_app *self);
int julia(int i, int j, t_app *self);

// Utils
void	usage(void);
int	create_trgb(int t, int r, int g, int b);
t_point complex_squared(t_point complex);
t_bool	ft_streq(char const *s1, char const *s2);
double	ft_atod(char* str);
t_bool	ft_isfloat(char *str);
int	ft_strcmp(char const *s1, char const *s2);

#endif

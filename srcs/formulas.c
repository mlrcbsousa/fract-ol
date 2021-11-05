/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:56:50 by msousa            #+#    #+#             */
/*   Updated: 2021/11/04 21:03:48 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(int i, int j, t_app *self)
{
	int iterations;
	t_point z;

	iterations = 0;
	z = (t_point){
			.x = range_map(i, WINDOW_X, self->axis_x),
			.y = range_map(j, WINDOW_Y, self->axis_y)};

	while (iterations < MAX_ITERATIONS)
	{
		if (pow(z.x, 2.0) + pow(z.y, 2.0) > 4.0)
			break;
		z = point_add(complex_squared(z), self->c);
		iterations++;
	}
	return (iterations);
}

int mandelbrot(int i, int j, t_app *self)
{
	int iterations;
	t_point z;
	t_point c;

	iterations = 0;
	z = (t_point){ 0.0, 0.0 };
	c = (t_point){
			.x = range_map(i, WINDOW_X, self->axis_x),
			.y = range_map(j, WINDOW_Y, self->axis_y)};

	while (iterations < MAX_ITERATIONS)
	{
		if (pow(z.x, 2.0) + pow(z.y, 2.0) > 4.0)
			break;
		z = point_add(complex_squared(z), c);
		iterations++;
	}
	return (iterations);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:12:36 by msousa            #+#    #+#             */
/*   Updated: 2021/11/08 09:57:11 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point point_add(t_point a, t_point b)
{
	t_point result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_point complex_squared(t_point point)
{
	t_point result;

	result.x = pow(point.x, 2.0) - pow(point.y, 2.0);
	result.y = 2.0 * point.x * point.y;
	return (result);
}

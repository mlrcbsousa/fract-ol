/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:53:43 by msousa            #+#    #+#             */
/*   Updated: 2021/11/04 21:02:44 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point complex_squared(t_point point)
{
	t_point	result;

	result.x = pow(point.x, 2.0) - pow(point.y, 2.0); 
	result.y = 2.0 * point.x * point.y;
	return (result);
}


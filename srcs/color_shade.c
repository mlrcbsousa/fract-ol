/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:24:56 by msousa            #+#    #+#             */
/*   Updated: 2021/11/03 14:49:05 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"
#include <stdio.h>

// add_shade is a function that accepts a double(distance) and a int(color) as
// arguments, 0 will add no shading to the color, whilst 1 will make the color
// completely dark.0.5 will dim it halfway, and.25 a quarter way.You get the
// point.

int	add_shade(int color, double distance)
{
	if (distance < 0 || distance > 1)
		return (-1);
	return (create_trgb((int)(distance * (double)get_t(color)),
											(int)(distance * (double)get_r(color)),
											(int)(distance * (double)get_g(color)),
											(int)(distance * (double)get_b(color))));
}

// get_opposite is a function that accepts a int(color) as argument and that
// will invert the color accordingly.

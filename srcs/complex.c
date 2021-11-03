/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:53:43 by msousa            #+#    #+#             */
/*   Updated: 2021/11/03 12:48:56 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

t_point complex_squared(t_point point)
{
	t_point	result;

	result.x = point.x * point.x - point.y * point.y;
	result.y = 2.0 * point.x * point.y;
	return (result);
}


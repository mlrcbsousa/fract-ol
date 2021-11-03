/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:12:36 by msousa            #+#    #+#             */
/*   Updated: 2021/11/03 12:49:03 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

t_point point_add(t_point a, t_point b)
{
	t_point result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

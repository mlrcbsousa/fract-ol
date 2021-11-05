/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:47:39 by msousa            #+#    #+#             */
/*   Updated: 2021/11/05 11:28:54 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_range.h"

double	range_size(t_range range)
{
	return (range.max - range.min);
}

double	range_map(double n, t_range from, t_range to)
{
	return to.min + (n / range_size(from) * range_size(to));
}

t_range range_move(t_range range, double n)
{
	t_range result;

	result.max = range.max + n;
	result.min = range.min + n;
	return (result);
}

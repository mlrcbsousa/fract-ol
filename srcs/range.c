/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:47:39 by msousa            #+#    #+#             */
/*   Updated: 2021/11/03 15:54:28 by msousa           ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:49:38 by msousa            #+#    #+#             */
/*   Updated: 2021/11/09 22:27:10 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANGE_H
# define FT_RANGE_H

struct	s_range
{
	double	min;
	double	max;
};

typedef struct s_range	t_range;

double	range_map(double n, t_range from, t_range to);
double	range_size(t_range range);
t_range	range_move(t_range range, double n);
t_range	range_resize(t_range range, double ratio);

#endif

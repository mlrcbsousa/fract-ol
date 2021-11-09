/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:29:05 by msousa            #+#    #+#             */
/*   Updated: 2021/11/09 22:27:42 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

struct	s_point
{
	double	x;
	double	y;
};

typedef struct s_point	t_point;

t_point	point_add(t_point a, t_point b);

#endif

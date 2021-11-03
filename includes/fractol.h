/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:34 by msousa            #+#    #+#             */
/*   Updated: 2021/11/03 16:11:13 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_color.h"
# include "ft_point.h"
# include "ft_range.h"
# include "ft_mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 200

void	  fractol(void);
t_point complex_squared(t_point complex);

#endif

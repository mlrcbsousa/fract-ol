/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:08:07 by msousa            #+#    #+#             */
/*   Updated: 2021/11/03 15:56:23 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MLX_H
# define FT_MLX_H

# include <mlx.h>

struct s_image
{
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
};

typedef struct s_image t_image;

void my_mlx_pixel_put(t_image *data, int x, int y, int color);

#endif

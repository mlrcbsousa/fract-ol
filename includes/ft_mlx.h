/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:08:07 by msousa            #+#    #+#             */
/*   Updated: 2021/11/05 11:00:54 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MLX_H
# define FT_MLX_H

# include <mlx.h>

# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)
# define BUTTON_PRESS 4

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ARROW_UP	126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define KEY_ESC 53
# define KEY_C 8
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

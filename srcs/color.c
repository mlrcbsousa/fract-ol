/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:58:28 by msousa            #+#    #+#             */
/*   Updated: 2021/11/02 17:46:43 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://stackoverflow.com/questions/2342114/extracting-rgb-color-component\
// s-from-integer-value

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
	return ((trgb & 0xFF000000) >> 24);
}

int get_r(int trgb)
{
	return ((trgb & 0x00FF0000) >> 16);
}

int get_g(int trgb)
{
	return ((trgb & 0x0000FF00) >> 8);
}

int get_b(int trgb)
{
	return ((trgb & 0x000000FF) >> 0);
}

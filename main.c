/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:00:32 by msousa            #+#    #+#             */
/*   Updated: 2021/11/02 17:50:01 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	int	trgb;

	// fractol();
	trgb = create_trgb(0, 255, 200, 100);
	ft_printf("Create R255 G200 B100: %d\n", trgb);
	ft_printf("Create R204 G160 B80: %d\n", create_trgb(0, 204, 160, 80));
	ft_printf("Add shade: %d\n", add_shade(trgb, 0.8));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:59:55 by msousa            #+#    #+#             */
/*   Updated: 2021/11/04 23:29:46 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_bool	ft_streq(char const *s1, char const *s2)
{
	return (s1 && s2 && ft_ternary(ft_strcmp(s1, s2), FALSE, TRUE));
}

#include <stdio.h>

double	ft_atod(char* str)
{
	char **strs;
	double	n;

	strs = ft_split(str, '.');
	ft_printf("strs: %d\n", ft_atoi(*strs));
	n = (double)ft_atoi(*strs);
	// printf("n: %lf\n", n);

	n += (double)ft_atoi(*(strs + 1)) / ((double)ft_strlen(*(strs + 1)) * 10);
	free(strs);
	return (n);
}

t_bool	ft_isfloat(char *str)
{
	// ft_putendl_fd(str, 1);
	if (!str || (*str != '-' && !ft_isdigit(*str)) || 
			(*str == '-' && *(str + 1) == '.'))
		return (FALSE);
	str++;
	while (*str && *str != '.')
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	if (!*str)
		return (TRUE);
	if (*str == '.')
	{
		str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (FALSE);
			str++;
		}
	}
	return (TRUE);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	while ((*s1 != '\0' && *s2 != '\0')
			&& (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}

void	usage(void)
{
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("Usage: ./fractol <name> <a> <b>", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("   - name   Name of fractal to display", 1);
	ft_putendl_fd("            options: Mandelbrot", 1);
	ft_putendl_fd("                     Julia", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("   - a      Only if fractal choice is Julia", 1);
	ft_putendl_fd("            real component of constant C", 1);
	ft_putendl_fd("            double in the form (-)0.0", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("   - b      Only if fractal choice is Julia", 1);
	ft_putendl_fd("            imaginary component of constant C", 1);
	ft_putendl_fd("            double in the form (-)0.0", 1);
	ft_putendl_fd(NULL, 1);
	exit(0);
}
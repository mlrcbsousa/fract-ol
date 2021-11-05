/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:59:55 by msousa            #+#    #+#             */
/*   Updated: 2021/11/05 09:15:34 by msousa           ###   ########.fr       */
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

double	ft_atof(char* str)
{
	char **strs;
	double	n;
	int	sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	strs = ft_split(str, '.');
	n = sign * ((double)ft_atoi(*strs) +
			(double)ft_atoi(*(strs + 1)) / pow(10, (double)ft_strlen(*(strs + 1))));
	free(strs);
	return (n);
}

t_bool	ft_isfloat(char *str)
{
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
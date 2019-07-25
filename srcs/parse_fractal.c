/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 23:14:52 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/29 23:14:53 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_fractal1(t_fractal *f, char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
	{
		f->indice = 0;
		f->name = ft_strdup("MANDELBROT");
	}
	else if (!ft_strcmp(name, "julia"))
	{
		f->indice = 1;
		f->name = ft_strdup("JULIA");
	}
	else if (!ft_strcmp(name, "burning_ship"))
	{
		f->indice = 2;
		f->name = ft_strdup("BURNING SHIP");
	}
	else if (!ft_strcmp(name, "tricorn"))
	{
		f->indice = 3;
		f->name = ft_strdup("TRICORN");
	}
	else
	{
		f->indice = 4;
		f->name = ft_strdup("CUBIC MANDELBROT");
	}
}

void	parse_fractal(t_fractal *f, char *name)
{
	if (!ft_strcmp(name, "mandelbrot") || !ft_strcmp(name, "julia") ||
!ft_strcmp(name, "burning_ship") || !ft_strcmp(name, "tricorn") ||
!ft_strcmp(name, "cubic_mandelbrot"))
		parse_fractal1(f, name);
	else if (!ft_strcmp(name, "fourth_mandelbrot"))
	{
		f->indice = 5;
		f->name = ft_strdup("4TH MANDELBROT");
	}
	else if (!ft_strcmp(name, "cubic_mandelbar"))
	{
		f->indice = 6;
		f->name = ft_strdup("CUBIC MANDELBAR");
	}
	else if (!ft_strcmp(name, "fourth_mandelbar"))
	{
		f->indice = 7;
		f->name = ft_strdup("4TH MANDELBAR");
	}
	else
	{
		f->indice = -1;
		ft_putstr("Error: Unavailable fractal!\n");
		print_usage();
	}
}

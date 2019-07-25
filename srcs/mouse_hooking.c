/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 14:36:17 by slaanani          #+#    #+#             */
/*   Updated: 2019/06/16 14:36:18 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_fractal *f, double mousere, double mouseim, double zoomfact)
{
	double interpolation;

	interpolation = 1.0 / zoomfact;
	f->remin = interpolate(mousere, f->remin, interpolation);
	f->immin = interpolate(mouseim, f->immin, interpolation);
	f->remax = interpolate(mousere, f->remax, interpolation);
	f->immax = interpolate(mouseim, f->immax, interpolation);
}

int		mouse_move(int x, int y, t_fractal *f)
{
	if (f->move == 1)
	{
		f->julia.c.re = -1.0 + ((double)x - 0) * 2.0 / (W - 0);
		f->julia.c.im = -1.0 + ((double)y - 0) * 2.0 / (H - 0);
	}
	if (f->move == 1 && f->indice == 1)
		put_fractal(f);
	return (0);
}

int		mouse_press(int button, int x, int y, t_fractal *f)
{
	f->mousere = f->remin + (double)x / (W / (f->remax - f->remin));
	f->mouseim = f->immin + (double)y / (H / (f->immax - f->immin));
	if (button == 5)
	{
		applyzoom(f, f->mousere, f->mouseim, f->zoomfactor);
		put_fractal(f);
	}
	if (button == 4)
	{
		applyzoom(f, f->mousere, f->mouseim, 1.0 / f->zoomfactor);
		put_fractal(f);
	}
	return (0);
}

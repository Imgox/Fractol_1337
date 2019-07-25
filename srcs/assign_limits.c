/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_limits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 01:32:42 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/29 01:32:44 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	assign_limits1(t_fractal *f)
{
	if (f->indice == 0)
	{
		f->remin = -2;
		f->remax = 1;
		f->immin = -1;
		f->immax = 1;
		f->max_iter = 190;
	}
	else if (f->indice == 1)
	{
		f->remin = -2;
		f->remax = 2;
		f->immin = -1.5;
		f->immax = 1.5;
		f->max_iter = 170;
	}
	else
	{
		f->remin = -2.23;
		f->remax = 1.27;
		f->immin = -1.61;
		f->immax = 0.59;
		f->max_iter = 100;
	}
}

void	assign_limits2(t_fractal *f)
{
	if (f->indice == 3)
	{
		f->remin = -2.49;
		f->remax = 2.08;
		f->immin = -1.54;
		f->immax = 1.51;
		f->max_iter = 100;
	}
	else if (f->indice == 4)
	{
		f->remin = -2.07;
		f->remax = 1.90;
		f->immin = -1.31;
		f->immax = 1.34;
		f->max_iter = 100;
	}
	else
	{
		f->remin = -1.79;
		f->remax = 1.67;
		f->immin = -1.15;
		f->immax = 1.15;
		f->max_iter = 100;
	}
}

void	assign_limits(t_fractal *f)
{
	if (f->indice == 0 || f->indice == 1 || f->indice == 2)
		assign_limits1(f);
	else if (f->indice == 3 || f->indice == 4 || f->indice == 5)
		assign_limits2(f);
	else if (f->indice == 6)
	{
		f->remin = -1.79;
		f->remax = 1.67;
		f->immin = -1.15;
		f->immax = 1.15;
		f->max_iter = 100;
	}
	else
	{
		f->remin = -1.74;
		f->remax = 1.72;
		f->immin = -1.15;
		f->immax = 1.15;
		f->max_iter = 100;
	}
}

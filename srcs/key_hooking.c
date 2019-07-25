/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:41:39 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/21 02:41:41 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_close(t_fractal *f)
{
	mlx_destroy_image(f->mlx.ptr, f->mlx.img.img);
	mlx_destroy_window(f->mlx.ptr, f->mlx.win);
	free(f->col.color);
	exit(0);
}

void	modify_iter(t_fractal *f, int keycode)
{
	if (keycode == PLUS)
		f->max_iter += 5;
	else if (f->max_iter > 0)
		f->max_iter -= 5;
	put_fractal(f);
}

void	move(t_fractal *f, int keycode)
{
	if (keycode == LEFT)
	{
		f->remin += 2 * ((f->remax - f->remin) / W);
		f->remax += 2 * ((f->remax - f->remin) / W);
		put_fractal(f);
	}
	else if (keycode == RIGHT)
	{
		f->remin -= 2 * ((f->remax - f->remin) / W);
		f->remax -= 2 * ((f->remax - f->remin) / W);
		put_fractal(f);
	}
	else if (keycode == UP)
	{
		f->immin += 2 * ((f->remax - f->remin) / W);
		f->immax += 2 * ((f->remax - f->remin) / W);
		put_fractal(f);
	}
	else
	{
		f->immin -= 2 * ((f->remax - f->remin) / W);
		f->immax -= 2 * ((f->remax - f->remin) / W);
		put_fractal(f);
	}
}

int		key_press(int keycode, t_fractal *f)
{
	if (keycode == ESC)
		ft_close(f);
	if (keycode == PLUS || keycode == MINUS)
		modify_iter(f, keycode);
	if (keycode == R)
	{
		assign_limits(f);
		put_fractal(f);
	}
	if (keycode == C)
	{
		f->col.indice = (f->col.indice + 1) % 5;
		put_fractal(f);
	}
	if (keycode == N)
	{
		f->indice = (f->indice + 1) % 8;
		assign_limits(f);
		put_fractal(f);
	}
	if (keycode == 46)
		f->move = (f->move == 0) ? 1 : 0;
	if (keycode == RIGHT || keycode == LEFT || keycode == UP || keycode == DOWN)
		move(f, keycode);
	return (0);
}

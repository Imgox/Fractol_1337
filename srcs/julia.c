/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 22:07:27 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/10 21:50:13 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			calculate_iter_julia(t_complex c, t_complex z0, int max_iter)
{
	t_complex	z;
	int			n;
	double		t;

	n = 0;
	z = z0;
	while ((z.re * z.re) + (z.im * z.im) <= 20 && n < max_iter)
	{
		t = z.re;
		z.re = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = 2 * t * z.im + c.im;
		n++;
	}
	if (n != max_iter)
		return (n);
	return (max_iter);
}

void		*calculate0j(void *arg)
{
	t_point		p;
	t_complex	z0;
	t_fractal	*f;
	int			m;

	f = (t_fractal *)arg;
	p = (t_point){.x = 0.0, .y = 0.0};
	while (p.y < H / 2)
	{
		p.x = 0;
		while (p.x < W / 2)
		{
			z0.re = f->remin + (p.x - 0) * (f->remax - f->remin) / (W - 0);
			z0.im = f->immin + (p.y - 0) * (f->immax - f->immin) / (H - 0);
			m = calculate_iter_julia(f->julia.c, z0, f->max_iter);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate1j(void *arg)
{
	t_point		p;
	t_complex	z0;
	t_fractal	*f;
	int			m;

	f = (t_fractal *)arg;
	p = (t_point){.x = W / 2, .y = 0.0};
	while (p.y < H / 2)
	{
		p.x = W / 2;
		while (p.x < W)
		{
			z0.re = f->remin + (p.x - 0) * (f->remax - f->remin) / (W - 0);
			z0.im = f->immin + (p.y - 0) * (f->immax - f->immin) / (H - 0);
			m = calculate_iter_julia(f->julia.c, z0, f->max_iter);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate2j(void *arg)
{
	t_point		p;
	t_complex	z0;
	t_fractal	*f;
	int			m;

	f = (t_fractal *)arg;
	p = (t_point){.x = 0.0, .y = H / 2};
	while (p.y < H)
	{
		p.x = 0;
		while (p.x < W / 2)
		{
			z0.re = f->remin + (p.x - 0) * (f->remax - f->remin) / (W - 0);
			z0.im = f->immin + (p.y - 0) * (f->immax - f->immin) / (H - 0);
			m = calculate_iter_julia(f->julia.c, z0, f->max_iter);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate3j(void *arg)
{
	t_point		p;
	t_complex	z0;
	t_fractal	*f;
	int			m;

	f = (t_fractal *)arg;
	p = (t_point){.x = W / 2, .y = H / 2};
	while (p.y < H)
	{
		p.x = W / 2;
		while (p.x < W)
		{
			z0.re = f->remin + (p.x - 0) * (f->remax - f->remin) / (W - 0);
			z0.im = f->immin + (p.y - 0) * (f->immax - f->immin) / (H - 0);
			m = calculate_iter_julia(f->julia.c, z0, f->max_iter);
			f->mlx.img.data[(int)(p.x + ((int)p.y * W))] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

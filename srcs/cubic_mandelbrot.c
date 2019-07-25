/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 05:27:00 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 05:27:01 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			calculate_iter_cubic_mandelbrot(t_complex c, t_fractal *f)
{
	t_complex	z;
	int			n;
	double		t;
	int			minusplus;

	minusplus = f->indice == 4 ? 1 : -1;
	n = 0;
	z = (t_complex){.re = 0, .im = 0};
	while ((z.re * z.re) + (z.im * z.im) <= 4 && n < f->max_iter)
	{
		t = z.re;
		z.re = (z.re * z.re * z.re) - 3 * (z.re * z.im * z.im) + c.re;
		z.im = minusplus * (3 * t * t * z.im - (z.im * z.im * z.im)) + c.im;
		n++;
	}
	if (n != f->max_iter)
		return (n + 1 - log(log2(sqrt(z.re * z.re + z.im * z.im))));
	return (f->max_iter);
}

void		*calculate0cm(void *arg)
{
	t_point		p;
	t_complex	c;
	t_fractal	*f;
	int			m;

	f = (t_fractal *)arg;
	p = (t_point){.x = 0.0, .y = 0.0};
	while (p.y < H / 2)
	{
		p.x = 0;
		while (p.x < W / 2)
		{
			c.re = f->remin + (p.x - 0) * (f->remax - f->remin) / (W - 0);
			c.im = f->immin + (p.y - 0) * (f->immax - f->immin) / (H - 0);
			m = calculate_iter_cubic_mandelbrot(c, f);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate1cm(void *arg)
{
	t_point		p;
	t_complex	c;
	t_fractal	*f;
	int			m;

	f = (t_fractal *)arg;
	p = (t_point){.x = W / 2, .y = 0.0};
	while (p.y < H / 2)
	{
		p.x = W / 2;
		while (p.x < W)
		{
			c.re = f->remin + (p.x - 0) * (f->remax - f->remin) / (W - 0);
			c.im = f->immin + (p.y - 0) * (f->immax - f->immin) / (H - 0);
			m = calculate_iter_cubic_mandelbrot(c, f);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate2cm(void *arg)
{
	t_point		p;
	t_complex	c;
	t_fractal	*f;
	int			m;

	f = (t_fractal *)arg;
	p = (t_point){.x = 0.0, .y = H / 2};
	while (p.y < H)
	{
		p.x = 0;
		while (p.x < W / 2)
		{
			c.re = f->remin + (p.x - 0) * (f->remax - f->remin) / (W - 0);
			c.im = f->immin + (p.y - 0) * (f->immax - f->immin) / (H - 0);
			m = calculate_iter_cubic_mandelbrot(c, f);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate3cm(void *arg)
{
	t_point		p;
	t_complex	c;
	t_fractal	*f;
	int			m;

	f = (t_fractal *)arg;
	p = (t_point){.x = W / 2, .y = H / 2};
	while (p.y < H)
	{
		p.x = W / 2;
		while (p.x < W)
		{
			c.re = f->remin + (p.x - 0) * (f->remax - f->remin) / (W - 0);
			c.im = f->immin + (p.y - 0) * (f->immax - f->immin) / (H - 0);
			m = calculate_iter_cubic_mandelbrot(c, f);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

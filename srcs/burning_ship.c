/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 01:01:40 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/10 20:34:53 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			calculate_iter_burn(t_complex c, int max_iter)
{
	t_complex	z;
	int			n;
	double		t;

	n = 0;
	z = (t_complex){.re = 0, .im = 0};
	while ((z.re * z.re) + (z.im * z.im) <= 4 && n < max_iter)
	{
		t = z.re;
		z.re = fabs((z.re * z.re) - (z.im * z.im) + c.re);
		z.im = fabs(2 * t * z.im + c.im);
		n++;
	}
	if (n != max_iter)
		return (n + 1 - log(log2(sqrt(z.re * z.re + z.im * z.im))));
	else
		return (0);
}

void		*calculate0b(void *arg)
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
			m = calculate_iter_burn(c, f->max_iter);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate1b(void *arg)
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
			m = calculate_iter_burn(c, f->max_iter);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate2b(void *arg)
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
			m = calculate_iter_burn(c, f->max_iter);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

void		*calculate3b(void *arg)
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
			m = calculate_iter_burn(c, f->max_iter);
			f->mlx.img.data[(int)p.x + ((int)p.y * W)] = m != 0 ?
f->col.color[(int)(m * 499 / f->max_iter + f->col.indice * 500)] : 0;
			p.x++;
		}
		p.y++;
	}
	pthread_exit(NULL);
}

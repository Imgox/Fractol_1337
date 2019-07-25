/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:08:07 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/31 01:08:08 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_fractal *f)
{
	int i;

	pthread_create(&f->threads[0], NULL, calculate0m, (void *)f);
	pthread_create(&f->threads[1], NULL, calculate1m, (void *)f);
	pthread_create(&f->threads[2], NULL, calculate2m, (void *)f);
	pthread_create(&f->threads[3], NULL, calculate3m, (void *)f);
	i = 0;
	while (i < N)
	{
		pthread_join(f->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img.img, 0, 0);
}

void		julia(t_fractal *f)
{
	int i;

	pthread_create(&f->threads[0], NULL, calculate0j, (void *)f);
	pthread_create(&f->threads[1], NULL, calculate1j, (void *)f);
	pthread_create(&f->threads[2], NULL, calculate2j, (void *)f);
	pthread_create(&f->threads[3], NULL, calculate3j, (void *)f);
	i = 0;
	while (i < 4)
	{
		pthread_join(f->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img.img, 0, 0);
}

void		burning_ship(t_fractal *f)
{
	int i;

	pthread_create(&f->threads[0], NULL, calculate0b, (void *)f);
	pthread_create(&f->threads[1], NULL, calculate1b, (void *)f);
	pthread_create(&f->threads[2], NULL, calculate2b, (void *)f);
	pthread_create(&f->threads[3], NULL, calculate3b, (void *)f);
	i = 0;
	while (i < N)
	{
		pthread_join(f->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img.img, 0, 0);
}

void		cubic_mandelbrot(t_fractal *f)
{
	int i;

	pthread_create(&f->threads[0], NULL, calculate0cm, (void *)f);
	pthread_create(&f->threads[1], NULL, calculate1cm, (void *)f);
	pthread_create(&f->threads[2], NULL, calculate2cm, (void *)f);
	pthread_create(&f->threads[3], NULL, calculate3cm, (void *)f);
	i = 0;
	while (i < N)
	{
		pthread_join(f->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img.img, 0, 0);
}

void		fourth_mandelbrot(t_fractal *f)
{
	int i;

	pthread_create(&f->threads[0], NULL, calculate04m, (void *)f);
	pthread_create(&f->threads[1], NULL, calculate14m, (void *)f);
	pthread_create(&f->threads[2], NULL, calculate24m, (void *)f);
	pthread_create(&f->threads[3], NULL, calculate34m, (void *)f);
	i = 0;
	while (i < N)
	{
		pthread_join(f->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img.img, 0, 0);
}

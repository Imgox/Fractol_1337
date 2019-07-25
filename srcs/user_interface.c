/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 05:59:34 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/21 05:59:35 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putstr("╔══════════════════════════════════════════╗\n");
	ft_putstr("║       Usage: ./fractol <fractal>         ║\n");
	ft_putstr("╚══════════════════════════════════════════╝\n");
	ft_putstr("           ╔════════════════════╗           \n");
	ft_putstr("╔══════════╣ Available fractals ╠══════════╗\n");
	ft_putstr("║          ╚════════════════════╝          ║\n");
	ft_putstr("║                                          ║\n");
	ft_putstr("║                mandelbrot                ║\n");
	ft_putstr("║                  julia                   ║\n");
	ft_putstr("║               burning_ship               ║\n");
	ft_putstr("║                 tricorn                  ║\n");
	ft_putstr("║             cubic_mandelbrot             ║\n");
	ft_putstr("║             fourth_mandelbrot            ║\n");
	ft_putstr("║              cubic_mandelbar             ║\n");
	ft_putstr("║             fourth_mandelbar             ║\n");
	ft_putstr("║                                          ║\n");
	ft_putstr("╚══════════════════════════════════════════╝\n");
	exit(0);
}

void	print_infos(t_fractal *f)
{
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 10, WHITE,
"MAX ITERATIONS: ");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 170, 10, WHITE,
ft_itoa(f->max_iter));
	if (f->indice == 1)
	{
		mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 30, WHITE, "Re(c) * 10E3 =");
		mlx_string_put(f->mlx.ptr, f->mlx.win, 170, 30, WHITE,
ft_itoa((int)(f->julia.c.re * 1000)));
		mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 50, WHITE, "Im(c) * 10E3 =");
		mlx_string_put(f->mlx.ptr, f->mlx.win, 170, 50, WHITE,
ft_itoa((int)(f->julia.c.im * 1000)));
	}
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 670, WHITE,
"MOVE        : ARROWS");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 690, WHITE,
"ZOOM        : MOUSE WHEEL");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 710, WHITE, "CHANGE COLOR: C");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 730, WHITE, "NEXT FRACTAL: N");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 750, WHITE, "RESET LIMITS: R");
	mlx_string_put(f->mlx.ptr, f->mlx.win, 10, 770, WHITE, "EXIT        : ESC");
}

void	create_background(t_fractal *f)
{
	t_point	i;
	t_point	fi;

	i = (t_point){.x = 5.0, .y = 5.0};
	fi = (t_point){.x = 220.0, .y = f->indice == 1 ? 80.0 : 40.0};
	while (i.y < fi.y)
	{
		i.x = 5.0;
		while (i.x < fi.x)
		{
			f->mlx.img.data[(int)i.x + ((int)i.y * W)] = ((i.x == 5.0) ||
(i.x == fi.x - 1) || (i.y == fi.y - 1) || (i.y == 5.0)) ? 0xFFFFFF : 0xb3000000;
			i.x++;
		}
		i.y++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img.img, 0, 0);
}

void	create_background2(t_fractal *f)
{
	t_point	i;
	t_point	fi;

	i = (t_point){.x = 5.0, .y = 665.0};
	fi = (t_point){.x = 265.0, .y = 795.0};
	while (i.y < fi.y)
	{
		i.x = 5.0;
		while (i.x < fi.x)
		{
			f->mlx.img.data[(int)i.x + ((int)i.y * W)] = ((i.x == 5.0) ||
(i.x == fi.x - 1) || (i.y == fi.y - 1) || (i.y == 665)) ? 0xFFFFFF : 0xb3000000;
			i.x++;
		}
		i.y++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img.img, 0, 0);
}

void	user_interface(t_fractal *f)
{
	create_background(f);
	create_background2(f);
	print_infos(f);
}

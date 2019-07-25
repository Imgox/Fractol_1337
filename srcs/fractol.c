/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:34:16 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/10 22:17:06 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_fractal(t_fractal *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	if (f->indice == 0 || f->indice == 3)
		mandelbrot(f);
	else if (f->indice == 1)
		julia(f);
	else if (f->indice == 2)
		burning_ship(f);
	else if (f->indice == 4 || f->indice == 6)
		cubic_mandelbrot(f);
	else if (f->indice == 5 || f->indice == 7)
		fourth_mandelbrot(f);
	user_interface(f);
}

int		main(int argc, char **argv)
{
	t_fractal	f;

	if (argc != 2)
		print_usage();
	parse_fractal(&f, argv[1]);
	f.col.indice = 0;
	coloring(&f);
	f.mlx.ptr = mlx_init();
	f.mlx.win = mlx_new_window(f.mlx.ptr, W, H, f.name);
	f.mlx.img.img = mlx_new_image(f.mlx.ptr, W, H);
	f.mlx.img.data = (int *)mlx_get_data_addr(f.mlx.img.img, &f.mlx.img.bpp,
&f.mlx.img.sl, &f.mlx.img.endian);
	f.zoomfactor = 1.402;
	f.move = 1;
	assign_limits(&f);
	put_fractal(&f);
	mlx_hook(f.mlx.win, 2, 0, key_press, &f);
	mlx_hook(f.mlx.win, 6, 0, mouse_move, &f);
	mlx_hook(f.mlx.win, 4, 0, mouse_press, &f);
	mlx_loop(f.mlx.ptr);
	return (0);
}

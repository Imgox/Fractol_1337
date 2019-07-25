/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:57:05 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/10 21:52:38 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define H 400 * 2
# define W 600 * 2
# define ESC 53
# define PLUS 69
# define MINUS 78
# define R 15
# define C 8
# define N 45
# define M 46
# define Z 6
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define WHITE 0xFFFFFF
# define Z 6

typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

typedef struct	s_julia
{
	double		x;
	double		y;
	t_complex	c;
}				t_julia;

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		sl;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct	s_coloring
{
	int			*color;
	int			indice;
}				t_coloring;

typedef struct	s_fractal
{
	int			indice;
	char		*name;
	int			max_iter;
	double		remin;
	double		remax;
	double		immin;
	double		immax;
	t_mlx		mlx;
	double		zoomfactor;
	double		mousere;
	double		mouseim;
	t_coloring	col;
	t_julia		julia;
	int			move;
	t_complex	c;
	pthread_t	threads[4];
}				t_fractal;

int				calculate_iter_mandelbrot(t_complex c, t_fractal *f);
int				calculate_iter_julia(t_complex c, t_complex z0, int max_iter);
int				calculate_iter_burn(t_complex c, int max_iter);
int				calculate_iter_cubic_mandelbrot(t_complex c, t_fractal *f);
int				calculate_iter_4th_mandelbrot(t_complex c, t_fractal *f);
void			*calculate0m(void *arg);
void			*calculate1m(void *arg);
void			*calculate2m(void *arg);
void			*calculate3m(void *arg);
void			*calculate0j(void *arg);
void			*calculate1j(void *arg);
void			*calculate2j(void *arg);
void			*calculate3j(void *arg);
void			*calculate0b(void *arg);
void			*calculate1b(void *arg);
void			*calculate2b(void *arg);
void			*calculate3b(void *arg);
void			*calculate0cm(void *arg);
void			*calculate1cm(void *arg);
void			*calculate2cm(void *arg);
void			*calculate3cm(void *arg);
void			*calculate04m(void *arg);
void			*calculate14m(void *arg);
void			*calculate24m(void *arg);
void			*calculate34m(void *arg);
void			mandelbrot(t_fractal *f);
void			julia(t_fractal *f);
void			burning_ship(t_fractal *f);
void			cubic_mandelbrot(t_fractal *f);
void			fourth_mandelbrot(t_fractal *f);
void			coloring(t_fractal *f);
void			parse_fractal(t_fractal *f, char *name);
void			assign_limits(t_fractal *f);
void			put_fractal(t_fractal *f);
int				key_press(int keycode, t_fractal *f);
int				mouse_move(int x, int y, t_fractal *f);
int				mouse_press(int button, int x, int y, t_fractal *f);
void			print_usage(void);
void			user_interface(t_fractal *f);

#endif

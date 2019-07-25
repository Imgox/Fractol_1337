/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 23:17:05 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/20 23:17:07 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	coloring(t_fractal *f)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	f->col.color = (int *)malloc(2500 * sizeof(int));
	fd = open("./colors/index.col", O_RDONLY);
	i = 0;
	while (i < 2500)
	{
		get_next_line(fd, &line);
		f->col.color[i] = ft_atoi_base(line, 16);
		i++;
	}
	close(fd);
}

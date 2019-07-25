/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:39:06 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:39:07 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *zf;
	size_t i;

	i = 0;
	zf = (size_t *)malloc(sizeof(zf) * size);
	if (zf == NULL)
		return (NULL);
	while (i <= size)
	{
		zf[i] = 0;
		i++;
	}
	return (zf);
}

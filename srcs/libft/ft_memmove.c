/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:39:26 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:39:28 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*memdst;
	unsigned char	*memsrc;
	int				i;

	i = (int)len;
	memsrc = (unsigned char *)src;
	memdst = (unsigned char *)dst;
	if (src > dst)
		ft_memcpy(memdst, memsrc, len);
	else
		while (i--)
			memdst[i] = memsrc[i];
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:39:08 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:39:11 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *memdst;
	unsigned char *memsrc;
	unsigned char ch;

	memsrc = (unsigned char *)src;
	memdst = (unsigned char *)dst;
	ch = (unsigned char)c;
	while (n > 0)
	{
		*(memdst++) = *(memsrc++);
		if (*(memsrc - 1) == ch)
		{
			return (memdst);
		}
		n--;
	}
	return (NULL);
}

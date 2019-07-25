/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:39:19 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:39:22 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *memdst;
	unsigned char *memsrc;

	memsrc = (unsigned char *)src;
	memdst = (unsigned char *)dst;
	while (n--)
	{
		*(memdst++) = *(memsrc++);
	}
	return (dst);
}

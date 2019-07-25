/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:39:12 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:39:14 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *dst;

	dst = (unsigned char *)s;
	while (n--)
	{
		if (*dst == (unsigned char)c)
			return (dst);
		dst++;
	}
	return (NULL);
}

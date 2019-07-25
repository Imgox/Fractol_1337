/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:41:35 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:41:37 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int k;
	int l;
	int j;

	l = ft_strlen(src);
	i = ft_strlen(dst);
	k = (int)size;
	j = 0;
	if (k < i)
		l = l + k;
	else
		l = l + i;
	while (src[j] != '\0' && i + 1 < k)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (l);
}

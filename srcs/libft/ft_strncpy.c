/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:41:53 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:41:55 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;
	int k;

	i = 0;
	k = (int)len;
	while (i < k && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < k)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

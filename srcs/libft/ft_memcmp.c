/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:39:15 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:39:17 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s3;
	const unsigned char		*s4;
	int						i;

	i = 0;
	s3 = (const unsigned char *)s1;
	s4 = (const unsigned char *)s2;
	while (i < (int)n)
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	return (0);
}

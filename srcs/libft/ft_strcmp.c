/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:40:53 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:40:54 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *s3;
	const unsigned char *s4;
	int					i;

	i = 0;
	s3 = (const unsigned char *)s1;
	s4 = (const unsigned char *)s2;
	while (s3[i])
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	return (s3[i] - s4[i]);
}

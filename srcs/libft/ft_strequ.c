/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:41:18 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:41:20 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	const char		*s3;
	const char		*s4;
	int				i;

	i = 0;
	s3 = (const char *)s1;
	s4 = (const char *)s2;
	if (!s3 || !s4)
		return (0);
	while (i <= (int)ft_strlen(s3))
	{
		if (s3[i] != s4[i])
			return (0);
		i++;
	}
	return (1);
}

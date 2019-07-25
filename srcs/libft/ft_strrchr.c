/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:42:09 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:42:14 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*str;
	char		*res;

	i = 0;
	res = NULL;
	str = (char *)s;
	while (i <= ft_strlen(s))
	{
		if (*str == (char)c)
			res = str;
		str++;
		i++;
	}
	return (res);
}

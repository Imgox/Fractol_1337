/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:42:05 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:42:07 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*nee;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	hay = (char *)haystack;
	nee = (char *)needle;
	if (!*nee)
		return (hay);
	k = ft_strlen(nee);
	while (hay[i] != '\0' && k <= (int)len - i)
	{
		if (hay[i] == nee[0])
		{
			while (hay[i + j] == nee[j] && nee[j] != '\0')
				j++;
			if (nee[j] == '\0')
				return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}

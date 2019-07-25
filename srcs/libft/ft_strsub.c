/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:42:23 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:42:26 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s3;
	size_t		i;

	i = 0;
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (s3 == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		s3[i] = s[start + i];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

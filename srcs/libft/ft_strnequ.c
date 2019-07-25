/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:41:58 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:41:59 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i <= ft_strlen(str1) && i < n)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

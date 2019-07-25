/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:42:02 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:42:04 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*zf;
	size_t	i;

	i = 0;
	zf = (char *)malloc(sizeof(char) * (size + 1));
	if (zf == NULL)
		return (NULL);
	while (i <= size)
	{
		zf[i] = '\0';
		i++;
	}
	zf[i] = '\0';
	return (zf);
}

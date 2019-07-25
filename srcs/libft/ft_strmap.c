/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:41:41 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:41:43 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*zf;
	char	*aux;
	size_t	i;

	i = 0;
	aux = (char *)s;
	if (aux == NULL)
		return (NULL);
	zf = (char *)malloc(sizeof(char) * (ft_strlen(aux) + 1));
	if (zf == NULL)
		return (NULL);
	while (i < ft_strlen(aux))
	{
		zf[i] = (*f)(aux[i]);
		i++;
	}
	zf[i] = '\0';
	return (zf);
}

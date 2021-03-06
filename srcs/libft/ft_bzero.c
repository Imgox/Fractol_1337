/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:38:03 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:38:05 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	int					i;
	unsigned char		*ss;

	i = 0;
	ss = (unsigned char *)s;
	while (i < (int)n)
	{
		ss[i] = '\0';
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:38:06 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:38:09 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_character(char *str, int c)
{
	int i;

	i = 0;
	c = (unsigned char)c;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

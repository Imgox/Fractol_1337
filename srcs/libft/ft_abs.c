/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:36:21 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:37:55 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}

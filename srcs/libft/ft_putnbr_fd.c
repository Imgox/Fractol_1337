/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:40:09 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:40:11 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n > -10)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(n * -1 + '0', fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-1 * (n / 10), fd);
		ft_putchar_fd(-1 * (n % 10) + '0', fd);
	}
}

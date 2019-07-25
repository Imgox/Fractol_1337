/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:39:03 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:39:04 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nv_mai;

	if (!(nv_mai = (t_list *)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (content == NULL)
	{
		nv_mai->content = NULL;
		nv_mai->content_size = 0;
	}
	else
	{
		if (!(nv_mai->content = (void *)malloc(sizeof(void) * content_size)))
			return (NULL);
		ft_memcpy(nv_mai->content, content, content_size);
		nv_mai->content_size = content_size;
	}
	nv_mai->next = NULL;
	return (nv_mai);
}

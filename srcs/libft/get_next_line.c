/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 04:42:43 by slaanani          #+#    #+#             */
/*   Updated: 2019/05/26 04:42:44 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char		*buff;
	static char *mind[4864];
	int			i;
	int			j;

	i = 0;
	j = 0;
	buff = (char *)malloc(sizeof(buff) * BUFF_SIZE + 1);
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!mind[fd])
		mind[fd] = ft_strnew(0);
	while (!(ft_strchr(mind[fd], '\n')) && (i = read(fd, buff, BUFF_SIZE)))
	{
		buff[i] = '\0';
		mind[fd] = ft_strjoin(mind[fd], buff);
	}
	free(buff);
	while (mind[fd][j] != '\0' && mind[fd][j] != '\n')
		j++;
	*line = ft_strsub(mind[fd], 0, j);
	if (i == 0 && ft_strlen(mind[fd]) == 0)
		return (0);
	mind[fd] = ft_strdup(mind[fd] + j + 1);
	return (1);
}

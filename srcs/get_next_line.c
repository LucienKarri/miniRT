/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicorncorp <unicorncorp@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:08:19 by unicorncorp       #+#    #+#             */
/*   Updated: 2021/01/26 12:05:08 by unicorncorp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*buf_s;
	char		*rd_s;
	int			fd_val;

    fd_val = 1;
	if (fd < 0 || !line || 1 <= 0)
		return (-1);
	if (!(rd_s = (char *)malloc(sizeof(char) * (1 + 1))))
		return (-1);
	while (search_nl(buf_s) == 0 && (fd_val = read(fd, rd_s, 1)) > 0)
	{
		rd_s[fd_val] = '\0';
		buf_s = ft_strjoin(buf_s, rd_s);
	}
	free(rd_s);
	if (fd_val == -1)
		return (-1);
	*line = ft_strdup(buf_s);
	buf_s = clean_s(buf_s);
	if (fd_val == 0 && !buf_s)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicorncorp <unicorncorp@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 06:48:29 by unicorncorp       #+#    #+#             */
/*   Updated: 2021/01/26 12:04:55 by unicorncorp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*arr;

	i = 0;
	n = 0;
	arr = (char *)malloc((ft_strl(s1) + ft_strl(s2) + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			arr[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[n] != '\0')
			arr[i++] = s2[n++];
	}
	arr[i] = '\0';
	free(s1);
	return (arr);
}

int	ft_strl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	search_nl(char *s)
{
	int	v;

	v = 0;
	if (!s)
		return (0);
	while (s[v] != '\0')
	{
		if (s[v] == '\n')
			return (1);
		v++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*arr;
	int		n;

	n = 0;
	while (s && s[n] != '\0' && s[n] != '\n')
		n++;
	arr = malloc((n + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	n = 0;
	while (s && s[n] != '\0' && s[n] != '\n')
	{
		arr[n] = s[n];
		n++;
	}
	arr[n] = '\0';
	return (arr);
}

char	*clean_s(char *s)
{
	char	*cs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	cs = (char *)malloc(sizeof(char) * ((ft_strl(s) - i) + 1));
	if (!cs)
		return (NULL);
	i++;
	while (s[i] != '\0')
		cs[j++] = s[i++];
	cs[j] = '\0';
	free(s);
	return (cs);
}

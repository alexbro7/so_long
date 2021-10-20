/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:37:43 by alebross          #+#    #+#             */
/*   Updated: 2021/10/19 20:07:27 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	gnl_error(int e)
{
	if (e == 0)
		write(1, "Error\nMalloc failed.\n", 21);
	if (e == 1)
		write(1, "Error\nCan't read.\n", 18);
	return (0);
}

static int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*gnl_addchar(char *line, char c)
{
	char	*ret;
	int		i;

	ret = NULL;
	ret = malloc(sizeof(char) * (gnl_strlen(line) + 2));
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (line[i] != '\0')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = c;
	ret[i + 1] = '\0';
	free(line);
	line = NULL;
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char	buf;
	int		res;

	*line = NULL;
	*line = malloc(sizeof(char));
	if (*line == NULL)
		return (gnl_error(0) - 1);
	*line[0] = '\0';
	res = read(fd, &buf, 1);
	while (res > 0)
	{
		if (buf == '\n')
			return (1);
		*line = gnl_addchar(*line, buf);
		if (line == NULL)
			return (gnl_error(0) - 1);
		res = read(fd, &buf, 1);
	}
	if (res == -1)
		return (gnl_error(1) - 1);
	return (res);
}

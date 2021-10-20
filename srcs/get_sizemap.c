/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sizemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:36:53 by alebross          #+#    #+#             */
/*   Updated: 2021/10/19 20:02:27 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file(char *f)
{
	int	fd;

	fd = open(f, O_RDONLY);
	if (fd == -1)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	get_sizemap_2(int *fd, char *line, int o, t_p *p)
{
	while (o)
	{
		o = get_next_line(*fd, &line);
		if (o < 0)
			return (0);
		if (ft_strlen(line) == 0)
		{
			free(line);
			line = NULL;
			close(*fd);
			return (1);
		}
		p->sy++;
		if (ft_strlen(line) != p->sx)
		{
			free(line);
			line = NULL;
			close(*fd);
			return (ft_error(NULL, 4));
		}
		free(line);
		line = NULL;
	}
	close(*fd);
	return (1);
}

int	get_sizemap(char *f, t_p *p)
{
	int		fd;
	int		o;
	char	*line;

	line = NULL;
	fd = open(f, O_RDONLY);
	o = get_next_line(fd, &line);
	if (o < 0)
		return (0);
	p->sx = ft_strlen(line);
	p->sy = 1;
	free(line);
	line = NULL;
	return (get_sizemap_2(&fd, line, o, p));
}

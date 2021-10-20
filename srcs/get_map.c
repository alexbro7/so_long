/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:36:47 by alebross          #+#    #+#             */
/*   Updated: 2021/10/19 19:58:35 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_map2(int fd, t_p *p)
{
	char	*line;
	int		i[2];

	i[0] = 1;
	i[1] = 0;
	while (i[1] < p->sy)
	{
		i[0] = get_next_line(fd, &line);
		p->map[i[1]] = ft_strcpy(p->map[i[1]], line);
		i[1]++;
		free(line);
	}
}

int	get_map(char *f, t_p *p)
{
	int	fd;
	int	i;

	fd = open(f, O_RDONLY);
	p->map = NULL;
	p->map = malloc(sizeof(char *) * p->sy);
	if (p->map == NULL)
		return (0);
	i = 0;
	while (i < p->sy)
	{
		p->map[i] = NULL;
		p->map[i] = malloc(sizeof(char) * (p->sx + 1));
		if (p->map[i] == NULL)
		{
			free_map(p->map, i);
			return (ft_error(NULL, 0));
		}
		i++;
	}
	get_map2(fd, p);
	close(fd);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:36:16 by alebross          #+#    #+#             */
/*   Updated: 2021/10/19 18:15:22 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_p(t_p *p)
{
	int	i[2];

	p->p = 0;
	p->e = 0;
	p->c = 0;
	i[0] = 0;
	while (i[0] < p->sy)
	{
		i[1] = 0;
		while (i[1] < p->sx)
		{
			if (p->map[i[0]][i[1]] == 'P')
			{
				p->p++;
				p->px = i[1];
				p->py = i[0];
			}
			if (p->map[i[0]][i[1]] == 'C')
				p->c++;
			if (p->map[i[0]][i[1]] == 'E')
				p->e++;
			i[1]++;
		}
		i[0]++;
	}
}

int	check_mapchar(t_p *p)
{
	int	i;
	int	j;

	j = 0;
	while (j < p->sy)
	{
		i = 0;
		while (i < p->sx)
		{
			if (p->map[j][i] != '1' && p->map[j][i] != '0' &&
				p->map[j][i] != 'P' && p->map[j][i] != 'C' &&
				p->map[j][i] != 'E')
				return (0);
			i++;
		}
		j++;
	}
	init_p(p);
	return (1);
}

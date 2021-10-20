/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:24:41 by alebross          #+#    #+#             */
/*   Updated: 2021/10/19 20:05:58 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	down(t_p *p)
{
	p->by = p->py;
	p->bx = p->px;
	p->py++;
	refresh(p);
}

static void	up(t_p *p)
{
	p->by = p->py;
	p->bx = p->px;
	p->py--;
	refresh(p);
}

static void	left(t_p *p)
{
	p->bx = p->px;
	p->by = p->py;
	p->px--;
	refresh(p);
}

static void	right(t_p *p)
{
	p->bx = p->px;
	p->by = p->py;
	p->px++;
	refresh(p);
}

int	deal_key(int key, t_p *p)
{
	if (key == 119 && p->map[p->py - 1][p->px] != '1')
		up(p);
	else if (key == 115 && p->map[p->py + 1][p->px] != '1')
		down(p);
	else if (key == 97 && p->map[p->py][p->px - 1] != '1')
		left(p);
	else if (key == 100 && p->map[p->py][p->px + 1] != '1')
		right(p);
	if (p->map[p->py][p->px] == 'C')
	{
		p->map[p->py][p->px] = '0';
		p->c--;
	}
	else if (p->map[p->py][p->px] == 'E' && p->c == 0)
	{
		write(1, "\nYou win !\n", 11);
		free_all(p);
	}
	if (key == 65307)
		free_all(p);
	return (0);
}

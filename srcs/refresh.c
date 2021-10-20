/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:37:24 by alebross          #+#    #+#             */
/*   Updated: 2021/10/19 20:06:18 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	refresh(t_p *p)
{
	p->i++;
	if (p->map[p->py][p->px] == 'E')
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr,
			p->tpe, p->px * 64, p->py * 64);
	else
		mlx_put_image_to_window(p->mlx_ptr,
			p->win_ptr, p->tp, p->px * 64, p->py * 64);
	if (p->map[p->by][p->bx] == 'E')
		mlx_put_image_to_window(p->mlx_ptr,
			p->win_ptr, p->te, p->bx * 64, p->by * 64);
	else
		mlx_put_image_to_window(p->mlx_ptr,
			p->win_ptr, p->tb, p->bx * 64, p->by * 64);
	write(1, "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", 15);
	write(1, "Score : ", 8);
	ft_putnbr(p->i);
}

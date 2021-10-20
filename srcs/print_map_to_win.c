/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:37:02 by alebross          #+#    #+#             */
/*   Updated: 2021/10/04 22:02:14 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	line(t_p p, int i, int j)
{
	if (p.map[i][j] == '1')
		mlx_put_image_to_window(p.mlx_ptr,
			p.win_ptr, p.tw, j * 64, i * 64);
	else if (p.map[i][j] == '0' || p.map[i][j] == 'P')
		mlx_put_image_to_window(p.mlx_ptr,
			p.win_ptr, p.tb, j * 64, i * 64);
	else if (p.map[i][j] == 'E')
		mlx_put_image_to_window(p.mlx_ptr,
			p.win_ptr, p.te, j * 64, i * 64);
	else if (p.map[i][j] == 'C')
		mlx_put_image_to_window(p.mlx_ptr,
			p.win_ptr, p.tc, j * 64, i * 64);
}

int	print_map_to_win(t_p *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->sy)
	{
		j = 0;
		while (j < p->sx)
		{
			line(*p, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr,
		p->tp, p->px * 64, p->py * 64);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:36:57 by alebross          #+#    #+#             */
/*   Updated: 2021/10/01 22:51:06 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_texture(t_p *p)
{
	p->tb = mlx_xpm_file_to_image(p->mlx_ptr,
			"./textures/bottom-64.xpm", &p->tx, &p->ty);
	p->tw = mlx_xpm_file_to_image(p->mlx_ptr,
			"./textures/wall-64t.xpm", &p->tx, &p->ty);
	p->tp = mlx_xpm_file_to_image(p->mlx_ptr,
			"./textures/player-64.xpm", &p->tx, &p->ty);
	p->tc = mlx_xpm_file_to_image(p->mlx_ptr,
			"./textures/collectible-64.xpm", &p->tx, &p->ty);
	p->te = mlx_xpm_file_to_image(p->mlx_ptr,
			"./textures/exit-64.xpm", &p->tx, &p->ty);
	p->tpe = mlx_xpm_file_to_image(p->mlx_ptr,
			"./textures/tpe-64.xpm", &p->tx, &p->ty);
}

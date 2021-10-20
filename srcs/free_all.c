/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:40:49 by alebross          #+#    #+#             */
/*   Updated: 2021/10/19 17:35:08 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_all(t_p *p)
{
	free_map(p->map, p->sy);
	mlx_destroy_image(p->mlx_ptr, p->tb);
	mlx_destroy_image(p->mlx_ptr, p->tw);
	mlx_destroy_image(p->mlx_ptr, p->tp);
	mlx_destroy_image(p->mlx_ptr, p->tc);
	mlx_destroy_image(p->mlx_ptr, p->te);
	mlx_destroy_image(p->mlx_ptr, p->tpe);
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	mlx_destroy_display(p->mlx_ptr);
	free(p->mlx_ptr);
	exit(0);
}

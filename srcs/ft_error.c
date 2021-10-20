/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:40:49 by alebross          #+#    #+#             */
/*   Updated: 2021/09/26 16:50:41 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(t_p *p, int i)
{
	printf("Error\n");
	if (i == 0)
		printf("Malloc failed.\n");
	if (i == 1)
		printf("Wrong number of arguments.\n");
	if (i == 2)
		printf("Wrong file name extension.\n");
	if (i == 3)
		printf("Can't open this file.\n");
	if (i == 4)
		printf("The map is not rectangular.\n");
	if (i == 5)
		printf("Wrong char. The map must be conposed of '10PCE' only\n");
	if (i == 6)
		printf("The map must be closed by walls('1')\n");
	if (i == 7)
		printf("The map must have at list one 'C', one 'E' and only one 'P'\n");
	if (i >= 5)
		free_map(p->map, p->sy);
	if (i >= 8)
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	return (0);
}

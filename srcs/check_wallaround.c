/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wallaround.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:36:25 by alebross          #+#    #+#             */
/*   Updated: 2021/10/04 18:32:34 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_wallaround(t_p p)
{
	int	i;
	int	j;

	j = 0;
	while (j < p.sy)
	{
		i = 0;
		while (i < p.sx)
		{
			if ((!i || !j || i == p.sx - 1 || j == p.sy - 1)
				&& p.map[j][i] != '1')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

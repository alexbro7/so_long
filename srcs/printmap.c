/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <alebross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:37:20 by alebross          #+#    #+#             */
/*   Updated: 2021/10/01 21:37:21 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	printmap(t_p p)
{
	int	i;

	i = 0;
	while (i < p.sy)
	{
		printf("%s\n", p.map[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:37:28 by alebross          #+#    #+#             */
/*   Updated: 2021/10/19 19:12:20 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_filename(char *f)
{
	int	i;

	i = ft_strlen(f);
	if (i < 4)
		return (0);
	if (f[i - 4] != '.' || f[i - 3] != 'b'
		|| f[i - 2] != 'e' || f[i - 1] != 'r')
		return (0);
	return (1);
}

int	main2(t_p p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	p.mlx_ptr = mlx_init();
	p.winx = p.sx * 64;
	p.winy = p.sy * 64;
	p.i = 0;
	p.bx = p.px;
	p.by = p.py;
	load_texture(&p);
	write(1, "Score : 0", 10);
	p.win_ptr = mlx_new_window(p.mlx_ptr, p.winx, p.winy, "so_long");
	if (!p.win_ptr)
		return (ft_error(&p, 8) + 1);
	print_map_to_win(&p);
	p.map[p.py][p.px] = '0';
	mlx_key_hook(p.win_ptr, deal_key, &p);
	mlx_hook(p.win_ptr, 33, 1L << 17, free_all, &p);
	mlx_hook(p.win_ptr, 15, 1L << 16, print_map_to_win, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_p	p;

	if (ac != 2)
		return (ft_error(NULL, 1) + 1);
	if (!check_filename(av[1]))
		return (ft_error(NULL, 2) + 1);
	if (!check_file(av[1]))
		return (ft_error(NULL, 3) + 1);
	if (!get_sizemap(av[1], &p))
		return (1);
	if (!get_map(av[1], &p))
		return (1);
	if (!check_mapchar(&p))
		return (ft_error(&p, 5) + 1);
	if (!check_wallaround(p))
		return (ft_error(&p, 6) + 1);
	if (p.c == 0 || p.e == 0 || p.p != 1)
		return (ft_error(&p, 7) + 1);
	return (main2(p));
}

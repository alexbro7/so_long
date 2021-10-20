/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:52:42 by alebross          #+#    #+#             */
/*   Updated: 2021/10/18 23:37:56 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_p
{
	char	**map;
	void	*win_ptr;
	void	*mlx_ptr;
	void	*tb;
	void	*tw;
	void	*tp;
	void	*tc;
	void	*te;
	void	*tpe;
	int		tx;
	int		ty;
	int		winx;
	int		winy;
	int		sx;
	int		sy;
	int		px;
	int		py;
	int		bx;
	int		by;
	int		p;
	int		e;
	int		c;
	int		i;
}			t_p;

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		get_next_line(int fd, char **line);
void	ft_putnbr(int n);
int		ft_error(t_p *p, int i);
int		get_sizemap(char *f, t_p *p);
int		get_map(char *f, t_p *p);
void	ft_putchar(char c);
void	printmap(t_p p);
void	free_map(char **map, int y);
int		check_mapchar(t_p *p);
int		check_wallaround(t_p p);
int		check_file(char *f);
int		free_all(t_p *p);
void	load_texture(t_p *p);
int		print_map_to_win(t_p *p);
int		deal_key(int key, t_p *p);
void	refresh(t_p *p);
void	ft_putnbr(int n);

#endif

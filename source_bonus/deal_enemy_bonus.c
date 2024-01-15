/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:40:49 by abettini          #+#    #+#             */
/*   Updated: 2024/01/15 13:57:23 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_enemy_event(int x, int y, t_game *g)
{
	int	check;

	check = 0;
	if (g->map.mat[y][x] == '0')
	{
		g->map.mat[y][x] = 'X';
	}
	else if (g->map.mat[y][x] == 'P')
	{
		ft_printf("\n\033[1m\033[1;31mGAME OVER!\033[0m\n");
		ft_close_game(g);
		ft_end(0);
	}
	else
	{
		check = 1;
	}
	return (check);
}

static int	ft_move_enemy(int x, int y, t_game *g)
{
	static int	m;
	int			check;

	check = 0;
	if (m == 0)
		check = ft_enemy_event(x + 1, y, g);
	else if (m == 1)
		check = ft_enemy_event(x, y + 1, g);
	else if (m == 2)
		check = ft_enemy_event(x - 1, y, g);
	else if (m == 3)
		check = ft_enemy_event(x, y - 1, g);
	if (check != 0)
		g->map.mat[y][x] = 'X';
	m++;
	if (m == 4)
		m = 0;
	return (0);
}

int	ft_deal_enemy(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.size.y)
	{
		x = 0;
		while (x < g->map.size.x)
		{
			if (g->map.mat[y][x] == 'F')
				ft_move_enemy(x, y, g);
			x++;
		}
		y++;
	}
	ft_replace('F', '0', &g->map);
	ft_replace('X', 'F', &g->map);
	return (0);
}

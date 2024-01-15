/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:52:40 by abettini          #+#    #+#             */
/*   Updated: 2024/01/15 13:55:42 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_event_check(char next_pos, t_game *g)
{
	if (next_pos == 'F')
	{
		write(1, "\nGAME OVER!\n", 12);
		ft_close_game(g);
	}
	else if (next_pos == 'E')
	{
		write(1, "\nVICTORY!\n", 10);
		ft_close_game(g);
	}
	else if (next_pos == 'C')
	{
		g->c_cur++;
	}
	return (0);
}

static int	ft_update_stats(t_game *g)
{
	ft_printf("\rMoves = %d", g->moves);
	ft_printf("\tCollectibles = %d", g->c_cur);
	return (0);
}

static int	ft_events(char next_pos, int x, int y, t_game *g)
{
	if (next_pos == '0' || next_pos == 'C'
		|| (next_pos == 'E' && g->c_cur == g->c_max))
	{
		g->moves++;
		ft_event_check(next_pos, g);
		ft_update_stats(g);
		g->map.mat[y][x] = 'P';
		g->map.mat[g->hero_pos.y][g->hero_pos.x] = '0';
		g->hero_pos.x = x;
		g->hero_pos.y = y;
	}
	return (0);
}

int	ft_deal_key(int tasto, t_game *g)
{
	if (tasto == 65307)
		ft_close_game(g);
	else if (tasto == 'w' || tasto == 65362)
		ft_events(g->map.mat[g->hero_pos.y - 1][g->hero_pos.x],
			g->hero_pos.x, g->hero_pos.y - 1, g);
	else if (tasto == 'a' || tasto == 65361)
		ft_events(g->map.mat[g->hero_pos.y][g->hero_pos.x - 1],
			g->hero_pos.x - 1, g->hero_pos.y, g);
	else if (tasto == 's' || tasto == 65364)
		ft_events(g->map.mat[g->hero_pos.y + 1][g->hero_pos.x],
			g->hero_pos.x, g->hero_pos.y + 1, g);
	else if (tasto == 'd' || tasto == 65363)
		ft_events(g->map.mat[g->hero_pos.y][g->hero_pos.x + 1],
			g->hero_pos.x + 1, g->hero_pos.y, g);
	return (0);
}

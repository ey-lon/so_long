/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:52:40 by abettini          #+#    #+#             */
/*   Updated: 2022/12/20 09:53:10 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_event_check(char next_pos, t_game *g)
{
	if (next_pos == 'F')
	{
		ft_printf("\n\033[1m\033[1;31mGAME OVER!\033[0m\n");
		ft_close_game(g);
		ft_end(0);
	}
	if (next_pos == 'E')
	{
		ft_printf("\n\033[1m\033[32mVICTORY!\033[0m\n");
		ft_close_game(g);
		ft_end(1);
	}
	if (next_pos == 'C')
		g->c_cur++;
	return (0);
}

static int	ft_update_stats(t_game *g)
{
	ft_display_stats(g, 0xFFFFFF);
	ft_printf("\rMoves = %d", g->moves);
	ft_printf("\tCollectibles = %d", g->c_cur);
	return (0);
}

static int	ft_events(char next_pos, int x, int y, t_game *g)
{
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'F'
		|| (next_pos == 'E' && g->c_cur == g->c_max))
	{
		ft_display_stats(g, 0x000000);
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

int	ft_deal_key(int key, t_game *g)
{
	if (key == 65307)
	{
		ft_close_game(g);
		main();
	}
	else if (key == 'w' || key == 65362)
		ft_events(g->map.mat[g->hero_pos.y - 1][g->hero_pos.x],
			g->hero_pos.x, g->hero_pos.y - 1, g);
	else if (key == 'a' || key == 65361)
		ft_events(g->map.mat[g->hero_pos.y][g->hero_pos.x - 1],
			g->hero_pos.x - 1, g->hero_pos.y, g);
	else if (key == 's' || key == 65364)
		ft_events(g->map.mat[g->hero_pos.y + 1][g->hero_pos.x],
			g->hero_pos.x, g->hero_pos.y + 1, g);
	else if (key == 'd' || key == 65363)
		ft_events(g->map.mat[g->hero_pos.y][g->hero_pos.x + 1],
			g->hero_pos.x + 1, g->hero_pos.y, g);
	return (0);
}

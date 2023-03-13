/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:45:31 by abettini          #+#    #+#             */
/*   Updated: 2023/01/20 11:45:34 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_game(t_game *g)
{
	ft_free_mat(g->map.mat);
	ft_free_sprites(g);
	mlx_destroy_window(g->game.mlx, g->game.win);
	mlx_destroy_display(g->game.mlx);
	free(g->game.mlx);
	return (0);
}

static int	ft_quit_game(t_game *g)
{
	ft_close_game(g);
	main();
	return (0);
}

static int	ft_game_start(t_game *g, char *str)
{
	ft_mat_reader(str, &g->map);
	free(str);
	g->game.mlx = mlx_init();
	ft_load_sprites(g);
	g->moves = 0;
	g->c_cur = 0;
	g->f = 0;
	g->game.win = ft_new_window(&g->game,
			g->map.size.x * g->sprites.size.x + 0,
			g->map.size.y * g->sprites.size.y + 32, "so_long");
	ft_display_stats(g, 0xFFFFFF);
	mlx_hook(g->game.win, 2, 1L << 0, ft_deal_key, g);
	mlx_hook(g->game.win, 17, 0, ft_quit_game, g);
	mlx_loop_hook(g->game.mlx, ft_display_mat, g);
	mlx_loop(g->game.mlx);
	return (0);
}

int	ft_game(char *path)
{
	t_game	g;
	char	*str;

	str = ft_strjoin("maps/", path);
	free(path);
	if (!ft_mat_check(str, &g))
	{
		ft_game_start(&g, str);
	}
	else
	{
		free(str);
		main();
	}
	return (0);
}

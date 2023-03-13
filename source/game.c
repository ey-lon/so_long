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

#include "so_long.h"

void	*ft_new_window(t_program *p, int widht, int height, char *name)
{
	void	*win;

	win = mlx_new_window(p->mlx, widht, height, name);
	p->win_size.x = widht;
	p->win_size.y = height;
	return (win);
}

int	ft_close_game(t_game *g)
{
	ft_free_mat(g->map.mat);
	ft_free_sprites(g);
	mlx_destroy_window(g->game.mlx, g->game.win);
	mlx_destroy_display(g->game.mlx);
	free(g->game.mlx);
	exit(0);
}

static int	ft_game_start(t_game *g, char *str)
{
	ft_mat_reader(str, &g->map);
	g->game.mlx = mlx_init();
	ft_load_sprites(g);
	g->moves = 0;
	g->c_cur = 0;
	g->game.win = ft_new_window(&g->game,
			g->map.size.x * g->sprites.size.x + 0,
			g->map.size.y * g->sprites.size.y + 0, "so_long");
	mlx_hook(g->game.win, 2, 1L << 0, ft_deal_key, g);
	mlx_hook(g->game.win, 17, 0, ft_close_game, g);
	mlx_loop_hook(g->game.mlx, ft_display_mat, g);
	mlx_loop(g->game.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc == 2)
	{
		if (ft_type_check(argv[1]))
			ft_printf("Error\nInvalid file type.\n");
		else if (!ft_mat_check(argv[1], &g))
			ft_game_start(&g, argv[1]);
	}
	else
	{
		ft_printf("Error\nInvalid number of arguments.\n");
	}
	return (0);
}

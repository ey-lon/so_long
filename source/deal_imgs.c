/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:29:56 by abettini          #+#    #+#             */
/*   Updated: 2023/01/11 16:29:58 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_new_sprite(t_game *g, char *path)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(g->game.mlx, path,
			&g->sprites.size.x, &g->sprites.size.y);
	return (ptr);
}

int	ft_load_sprites(t_game *g)
{
	g->sprites.wall = ft_new_sprite(g, "textures/1.xpm");
	g->sprites.floor = ft_new_sprite(g, "textures/0.xpm");
	g->sprites.coll = ft_new_sprite(g, "textures/C.xpm");
	g->sprites.exit1 = ft_new_sprite(g, "textures/E1.xpm");
	g->sprites.hero1 = ft_new_sprite(g, "textures/P1.xpm");
	g->sprites.enemy1 = ft_new_sprite(g, "textures/F1.xpm");
	return (0);
}

int	ft_free_sprites(t_game *g)
{
	mlx_destroy_image(g->game.mlx, g->sprites.wall);
	mlx_destroy_image(g->game.mlx, g->sprites.floor);
	mlx_destroy_image(g->game.mlx, g->sprites.coll);
	mlx_destroy_image(g->game.mlx, g->sprites.exit1);
	mlx_destroy_image(g->game.mlx, g->sprites.hero1);
	mlx_destroy_image(g->game.mlx, g->sprites.enemy1);
	return (0);
}

int	ft_print_sprite(t_game *g, void *sprite, t_vector coor)
{
	mlx_put_image_to_window(g->game.mlx, g->game.win,
		sprite, coor.x + 0, coor.y + 0);
	return (0);
}

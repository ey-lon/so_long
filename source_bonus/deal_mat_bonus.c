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

static int	ft_mat_size(t_mat *t)
{
	t->size.x = 0;
	t->size.y = 0;
	while (t->mat[0][t->size.x] != '\0')
		t->size.x++;
	while (1)
	{
		if (!t->mat[t->size.y])
		{
			break ;
		}
		t->size.y++;
	}
	return (0);
}

int	ft_mat_reader(char *path, t_mat *t)
{
	int		fd;
	char	*rawmat;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		rawmat = malloc(1);
		*rawmat = '\0';
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			rawmat = ft_free_join(rawmat, line);
		}
		t->mat = ft_split(rawmat, '\n');
		ft_mat_size(t);
		free(rawmat);
	}
	close(fd);
	return (fd);
}

static int	ft_check_print(char c, t_game *g)
{
	if (c == '1')
		ft_print_sprite(g, g->sprites.wall, g->sprite_pos);
	else if (c == '0')
		ft_print_sprite(g, g->sprites.floor, g->sprite_pos);
	else if (c == 'C')
		ft_print_sprite(g, g->sprites.coll, g->sprite_pos);
	else if (c == 'P' && g->f < \
			(A / (g->game.win_size.x * g->game.win_size.y)) / 2)
		ft_print_sprite(g, g->sprites.hero1, g->sprite_pos);
	else if (c == 'P')
		ft_print_sprite(g, g->sprites.hero2, g->sprite_pos);
	else if (c == 'E' && g->c_cur != g->c_max)
		ft_print_sprite(g, g->sprites.exit1, g->sprite_pos);
	else if (c == 'E')
		ft_print_sprite(g, g->sprites.exit2, g->sprite_pos);
	else if (c == 'F' && g->f < \
			(A / (g->game.win_size.x * g->game.win_size.y)) / 2)
		ft_print_sprite(g, g->sprites.enemy1, g->sprite_pos);
	else if (c == 'F')
		ft_print_sprite(g, g->sprites.enemy2, g->sprite_pos);
	return (0);
}

int	ft_display_mat(t_game *g)
{
	int	x;
	int	y;

	if (g->moves > 0 && g->f == A / (g->game.win_size.x * g->game.win_size.y))
		ft_deal_enemy(g);
	y = 0;
	g->sprite_pos.y = 0;
	while (y < g->map.size.y)
	{
		x = 0;
		g->sprite_pos.x = 0;
		while (x < g->map.size.x)
		{
			ft_check_print(g->map.mat[y][x], g);
			x++;
			g->sprite_pos.x += g->sprites.size.x;
		}
		y++;
		g->sprite_pos.y += g->sprites.size.y;
	}
	g->f++;
	if (g->f > A / (g->game.win_size.x * g->game.win_size.y))
		g->f = 0;
	return (0);
}

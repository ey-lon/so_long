/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:28:28 by abettini          #+#    #+#             */
/*   Updated: 2023/06/20 15:21:02 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_square_check(char **mat)
{
	int	check;
	int	y;

	y = 0;
	check = 0;
	while (mat[y] && check == 0)
	{
		if (ft_strlen(mat[y]) != ft_strlen(mat[0]))
			check = 1;
		y++;
	}
	return (check);
}

static int	ft_wall_check(char **mat, int xmax, int ymax)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (mat)
	{
		while (i < ymax && check == 0)
		{
			if (mat[i][0] != '1' || mat[i][xmax - 1] != '1')
				check = 1;
			i++;
		}
		i = 0;
		while (i < xmax && check == 0)
		{
			if (mat[0][i] != '1' || mat[ymax - 1][i] != '1')
				check = 1;
			i++;
		}
	}
	return (check);
}

static int	ft_char_check(t_game *g, int check)
{
	int	x;
	int	y;

	g->c_max = 0;
	y = 0;
	while (y < g->map.size.y)
	{
		x = 0;
		while (x < g->map.size.x)
		{
			if (g->map.mat[y][x] == 'C')
				g->c_max++;
			else if (g->map.mat[y][x] == 'P')
				check += 2;
			else if (g->map.mat[y][x] == 'E')
				check += 3;
			else if (g->map.mat[y][x] != '0' && g->map.mat[y][x] != '1')
				check += 4;
			x++;
		}
		y++;
	}
	if (check == 6 && g->c_max >= 1)
		check = 0;
	return (check);
}

static int	ft_path_check(t_game *g)
{
	int	res;
	int	check;

	g->hero_pos.y = 0;
	check = 0;
	while (g->map.mat[g->hero_pos.y] != 0 && check == 0)
	{
		g->hero_pos.x = 0;
		while (g->map.mat[g->hero_pos.y][g->hero_pos.x] != '\0' && check == 0)
		{
			if (g->map.mat[g->hero_pos.y][g->hero_pos.x] == 'P')
				check = 1;
			else
				g->hero_pos.x++;
		}
		if (!check)
			g->hero_pos.y++;
	}
	res = ft_flood_fill(g->map.mat, g->map.size, g->hero_pos);
	return (res);
}

int	ft_mat_check(char *path, t_game *g)
{
	int	err;
	int	check;

	check = ft_mat_reader(path, &g->map);
	err = 0;
	if (check == -1)
		err = ft_printf("Error\nMap does not exist.\n");
	else
	{
		if (ft_square_check(g->map.mat) != 0)
			err = ft_printf("Error\nMap is not rectangular.\n");
		if (ft_wall_check(g->map.mat, g->map.size.x, g->map.size.y))
			err = ft_printf("Error\nMap is not surrounded by walls.\n");
		if (ft_char_check(g, 1))
			err = ft_printf("Error\nInvalid elements.\n");
		if (ft_path_check(g))
			err = ft_printf("Error\nThe exit is unreachable.\n");
		ft_free_mat(g->map.mat);
	}
	return (err);
}

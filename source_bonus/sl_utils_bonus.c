/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:44:05 by abettini          #+#    #+#             */
/*   Updated: 2023/06/21 17:33:03 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_free_join(char *str1, char *str2)
{
	char	*str;

	str = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str);
}

int	ft_free_mat(char **mat)
{
	int	y;

	y = 0;
	while (mat[y])
	{
		free(mat[y]);
		y++;
	}
	free(mat);
	return (0);
}

int	ft_replace(char c1, char c2, t_mat *mat)
{
	int	x;
	int	y;

	y = 0;
	while (y < mat->size.y)
	{
		x = 0;
		while (x < mat->size.x)
		{
			if (mat->mat[y][x] == c1)
				mat->mat[y][x] = c2;
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_type_check(char *path)
{
	int	i;

	i = ft_strlen(path);
	i -= 4;
	if (i <= 0)
		return (1);
	if (path[i - 1] == '/')
		return (1);
	return (ft_strncmp(&path[i], ".ber", 5));
}

int	ft_display_stats(t_game *g, int color)
{
	char	*str;
	char	*str2;
	char	*str3;

	str2 = ft_itoa(g->moves);
	str = ft_strjoin("Moves: ", str2);
	mlx_string_put(g->game.mlx, g->game.win, 10, 12, color, str);
	free(str);
	free(str2);
	str2 = ft_itoa(g->c_cur);
	str3 = ft_strjoin("Collectibles: ", str2);
	free(str2);
	str2 = ft_strjoin(str3, " / ");
	free(str3);
	str3 = ft_itoa(g->c_max);
	str = ft_strjoin(str2, str3);
	free(str2);
	free(str3);
	mlx_string_put(g->game.mlx, g->game.win, 10, 27, color, str);
	free(str);
	return (0);
}

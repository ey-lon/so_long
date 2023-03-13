/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:08:51 by abettini          #+#    #+#             */
/*   Updated: 2023/01/19 12:08:52 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_display_info(t_menu *m)
{
	int	y;
	int	i;

	y = 75;
	mlx_put_image_to_window(m->menu.mlx, m->menu.win,
		m->img2, 0, 0);
	i = 0;
	while (m->info.mat[i])
	{
		mlx_string_put(m->menu.mlx, m->menu.win,
			42, y, BLACK, m->info.mat[i]);
		i++;
		y += 12;
	}
	return (0);
}

int	ft_display_menu(t_menu *m, int c1, int c2)
{
	m->page = 0;
	mlx_put_image_to_window(m->menu.mlx, m->menu.win,
		m->img, 0, 0);
	mlx_string_put(m->menu.mlx, m->menu.win, 270, 100,
		BLACK, "Select map");
	mlx_string_put(m->menu.mlx, m->menu.win, 270, 115,
		c1, m->maps.mat[m->opt.x]);
	mlx_string_put(m->menu.mlx, m->menu.win, 270, 130, c2, "info");
	return (0);
}

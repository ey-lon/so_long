/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:22:43 by abettini          #+#    #+#             */
/*   Updated: 2023/01/28 10:22:45 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_deal_end(t_end *e)
{
	mlx_destroy_image(e->end.mlx, e->img);
	mlx_destroy_window(e->end.mlx, e->end.win);
	mlx_destroy_display(e->end.mlx);
	free(e->end.mlx);
	main();
	return (0);
}

static int	ft_end_key(int key, t_end *e)
{
	if (key == 65307 || key == 65293)
		ft_deal_end(e);
	return (0);
}

int	ft_end(int res)
{
	t_end	e;

	e.end.mlx = mlx_init();
	if (!res)
		e.img = mlx_xpm_file_to_image(e.end.mlx, "textures/z_lose.xpm",
				&e.size.x, &e.size.y);
	else
		e.img = mlx_xpm_file_to_image(e.end.mlx, "textures/z_win.xpm",
				&e.size.x, &e.size.y);
	e.end.win = ft_new_window(&e.end, e.size.x, e.size.y, "so_long");
	mlx_put_image_to_window(e.end.mlx, e.end.win, e.img, 0, 0);
	mlx_hook(e.end.win, 2, 1L << 0, ft_end_key, &e);
	mlx_hook(e.end.win, 17, 0, ft_deal_end, &e);
	mlx_loop(e.end.mlx);
	return (0);
}

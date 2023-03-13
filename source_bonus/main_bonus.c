/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:17:14 by abettini          #+#    #+#             */
/*   Updated: 2023/01/11 15:17:17 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_new_window(t_program *p, int widht, int height, char *name)
{
	void	*win;

	win = mlx_new_window(p->mlx, widht, height, name);
	p->win_size.x = widht;
	p->win_size.y = height;
	return (win);
}

int	ft_close_menu(t_menu *m)
{
	mlx_destroy_image(m->menu.mlx, m->img);
	mlx_destroy_image(m->menu.mlx, m->img2);
	mlx_destroy_window(m->menu.mlx, m->menu.win);
	mlx_destroy_display(m->menu.mlx);
	free(m->menu.mlx);
	ft_free_mat(m->maps.mat);
	ft_free_mat(m->info.mat);
	return (0);
}

int	ft_close(t_menu *m)
{
	ft_close_menu(m);
	exit(0);
}

int	main(void)
{
	t_menu	m;

	if (ft_mat_reader("txt/list_maps.txt", &m.maps) != -1)
	{
		if (ft_mat_reader("txt/README.txt", &m.info) != -1)
		{
			m.opt.x = 0;
			m.opt.y = 0;
			m.menu.mlx = mlx_init();
			m.img = mlx_xpm_file_to_image(m.menu.mlx, "textures/z_menu.xpm",
					&m.size.x, &m.size.y);
			m.img2 = mlx_xpm_file_to_image(m.menu.mlx, "textures/z_info.xpm",
					&m.size.x, &m.size.y);
			m.menu.win = ft_new_window(&m.menu, m.size.x, m.size.y, "so_long");
			ft_display_menu(&m, COL_2, BLACK);
			mlx_hook(m.menu.win, 2, 1L << 0, ft_deal_menu, &m);
			mlx_hook(m.menu.win, 17, 0, ft_close, &m.menu);
			mlx_loop(m.menu.mlx);
		}
		else
			ft_printf("Error\nREADME.txt not found.\n");
	}
	else
		ft_printf("Error\nlist_maps.txt not found.\n");
	return (0);
}

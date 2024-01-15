/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:25:56 by abettini          #+#    #+#             */
/*   Updated: 2024/01/15 13:58:29 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_esc(t_menu *m)
{
	if (!m->page)
	{
		ft_close(m);
	}
	else
	{
		m->page = 0;
		m->opt.y = 0;
		m->opt.x = 0;
		ft_display_menu(m, COL_2, BLACK);
	}
	return (0);
}

static int	ft_enter(t_menu *m)
{
	char	*path;

	if (!m->opt.y)
	{
		path = ft_strdup(m->maps.mat[m->opt.x]);
		ft_close_menu(m);
		ft_game(path);
	}
	else
	{
		m->page++;
		ft_display_info(m);
	}
	return (0);
}

static int	ft_updown(t_menu *m)
{
	if (!m->opt.y)
	{
		m->opt.y++;
		ft_display_menu(m, BLACK, COL_2);
	}
	else
	{
		m->opt.y--;
		ft_display_menu(m, COL_2, BLACK);
	}
	return (0);
}

static int	ft_leftright(int key, t_menu *m)
{
	if (key == 65361 || key == 'a')
	{
		if (m->opt.x > 0)
			m->opt.x--;
		else
			m->opt.x = m->maps.size.y - 1;
	}
	else if (key == 65363 || key == 'd')
	{
		if (m->opt.x < m->maps.size.y - 1)
			m->opt.x++;
		else
			m->opt.x = 0;
	}
	ft_display_menu(m, COL_2, BLACK);
	return (0);
}

int	ft_deal_menu(int key, t_menu *m)
{
	if (key == 65307)
		ft_esc(m);
	else if (key == 65293 && !m->page)
		ft_enter(m);
	else if ((key == 65361 || key == 65363
			|| key == 'a' || key == 'd')
		&& !m->page && !m->opt.y)
		ft_leftright(key, m);
	else if ((key == 65362 || key == 65364
			|| key == 'w' || key == 's') && !m->page)
		ft_updown(m);
	return (0);
}

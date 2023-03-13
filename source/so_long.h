/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:59:26 by abettini          #+#    #+#             */
/*   Updated: 2023/01/16 10:56:03 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_mat
{
	char		**mat;
	t_vector	size;
}		t_mat;

typedef struct s_sprites
{
	void		*wall;
	void		*floor;
	void		*coll;
	void		*exit1;
	void		*hero1;
	void		*enemy1;
	t_vector	size;
}		t_sprites;

typedef struct s_program
{
	void		*mlx;
	void		*win;
	t_vector	win_size;
}		t_program;

typedef struct s_game
{
	t_program	game;
	t_mat		map;
	t_sprites	sprites;
	t_vector	sprite_pos;
	t_vector	hero_pos;
	int			c_max;
	int			c_cur;
	int			moves;
}		t_game;

int		ft_deal_key(int tasto, t_game *g);
int		ft_close_game(t_game *g);
int		ft_deal_enemy(t_game *g);
int		ft_mat_reader(char *path, t_mat *t);
int		ft_mat_check(char *path, t_game *p);
int		ft_display_mat(t_game *p);
int		ft_display_stats(t_game *g, int color);
int		ft_replace(char c1, char c2, t_mat *mat);
int		ft_free_mat(char **mat);
int		ft_flood_fill(char **tab, t_vector size, t_vector begin);
int		ft_load_sprites(t_game *g);
int		ft_free_sprites(t_game *g);
int		ft_print_sprite(t_game *g, void *sprite, t_vector coor);
int		ft_type_check(char *path);
char	*ft_free_join(char *str1, char *str2);
void	*ft_new_window(t_program *p, int widht, int height, char *name);

#endif

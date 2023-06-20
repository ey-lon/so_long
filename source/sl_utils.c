/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:44:05 by abettini          #+#    #+#             */
/*   Updated: 2023/06/20 15:13:04 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (i < 0)
		return (1);
	return (ft_strncmp(&path[i], ".ber", 5));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:14:54 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/18 09:05:15 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	fill_3(char **arr, int k, int i, int j)
{
	if ((i < 0 || i > k + 1 || j < 0 || j > ft_strlen_x(arr[0]) - 1)
		|| arr[i][j] == '1' || arr[i][j] == 'M' || arr[i][j] == 'E')
		return ;
	arr[i][j] = '1';
	fill_3(arr, k, i + 1, j);
	fill_3(arr, k, i - 1, j);
	fill_3(arr, k, i, j + 1);
	fill_3(arr, k, i, j - 1);
}

int	flood_fill_3(t_game *game)
{
	char	**new;
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	new = ft_split(game->arr, game->k);
	fill_3(new, game->k, game->pos_y / 65, game->pos_x / 65);
	while (i < game->k)
	{
		j = 0;
		while (new[i][j] && new[i][j] != '\n')
		{
			if (new[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	h = 0;
	while (h < game->k)
		free(new[h++]);
	free(new);
	return (1);
}

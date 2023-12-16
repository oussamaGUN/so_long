/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:14:54 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/16 12:06:06 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	fill(char **arr, int k, int i, int j)
{
	if ((i < 0 || i > k + 1 || j < 0 || j > ft_strlen_x(arr[0]) - 1)
		|| arr[i][j] == '1' || arr[i][j] == 'M')
		return ;
	arr[i][j] = '1';
	fill(arr, k, i + 1, j);
	fill(arr, k, i - 1, j);
	fill(arr, k, i, j + 1);
	fill(arr, k, i, j - 1);
}

char	**ft_split(char **s, int k)
{
	int		i;
	int		j;
	char	**arr;

	j = 0;
	i = 0;
	arr = malloc(sizeof(char *) * (k));
	if (!arr)
		return (NULL);
	while (i < k)
	{
		j = 0;
		arr[i] = malloc(sizeof(char) * ft_strlen_x(s[i]));
		while (s[i][j])
		{
			arr[i][j] = s[i][j];
			j++;
		}
		i++;
	}
	return (arr);
}

int	flood_fill(t_game *game)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_split(game->arr, game->k);
	fill(new, game->k, game->pos_y / 65, game->pos_x / 65);
	while (i < game->k)
	{
		j = 0;
		while (new[i][j] && new[i][j] != '\n')
		{
			if (new[i][j] != '1' && new[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

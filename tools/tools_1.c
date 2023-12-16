/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:59:42 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/16 16:05:37 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	strfind(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i] != '\n')
	{
		if (arr[i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_strlen_x(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_coins(t_game **game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < (*game)->k - 1)
	{
		j = 0;
		while ((*game)->arr[i][j])
		{
			if ((*game)->arr[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	get_line(t_game *game, char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		protect();
	game->k = 0;
	while (1)
	{
		game->arr[game->k] = get_next_line(fd);
		if (!game->arr[game->k])
			break ;
		game->k++;
	}
	if (!game->arr[game->k] && game->k == 0)
		protect();
	game->collect = ft_coins(&game);
	game->coins = 0;
	game->move_count = 1;
	close(fd);
}

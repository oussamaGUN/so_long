/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:22:44 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/16 11:26:58 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void if_else(char c, t_game **game)
{
	if (c == '1')
		render_wall(&game);
	else if (c == '0')
		render_ground(&game);
	else if (c == 'M')
		render_monster(&game);
	else if (c == 'E')
		render_door(&game);
	else if (c == 'P')
		render_player(&game);
}
void	map(t_game *game)
{
	int i;
	int j;

	j = -1;
	i = 0;
	while (++j < game->k)
	{
		i = 0;
		while (game->arr[j][i])
		{
			if_else(game->arr[j][i], &game);
			game->x += 65;
			i++;
		}
		game->x = 0;
		game->y += 65;
	}
}
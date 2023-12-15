/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:27:20 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/15 18:27:23 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

void	init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, ft_strlen_x(game->arr[0]) * 65,
			game->k * 65, "so long");
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac < 1)
	{
		write(1, "Error\n", 7);
		exit(0);
	}
	valid_name(av[1]);
	get_line(&game, av[1]);
	if (map_check(&game) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	init(&game);
	map(&game);
	if (flood_fill(&game) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_hook(game.win, 02, 0, key_hook, &game);
	mlx_loop(game.mlx);
}

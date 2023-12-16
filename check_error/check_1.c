/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:03:59 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/16 16:46:59 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	protect(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	protect1(void *mlx, void *img)
{
	write(1, "Error\n", 6);
	mlx_destroy_image(mlx, img);
	exit(0);
}

void	valid_name(char *s)
{
	char	*ber;
	int		len;
	int		i;

	ber = ".ber";
	len = ft_strlen(ber) - 1;
	i = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[i] != ber[len])
			protect();
		len--;
		i--;
	}
}

int	map_check(t_game *game)
{
	if (first_c(game->arr, game->k) == 0)
		return (0);
	if (second_c(game->arr, game->k) == 0)
		return (0);
	if (third_c(&game) == 0)
		return (0);
	return (1);
}

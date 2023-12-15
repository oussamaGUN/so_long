#include "../main.h"
void map(t_game *game)
{
	int i = 0;
	int j = 0;

	while (j < game->k)
	{
		i = 0;
		while (game->arr[j][i])
		{
			if (game->arr[j][i] == '1')
				render_wall(&game);
			else if (game->arr[j][i] == '0')
				render_ground(&game);
			else if (game->arr[j][i] == 'M')
				render_monster(&game);
			else if (game->arr[j][i] == 'E')
				render_door(&game);
			else if (game->arr[j][i] == 'P')
				render_player(&game);
			game->x += 65;
			i++;
		}
		game->x = 0;
		game->y += 65;
		j++;
    }
}
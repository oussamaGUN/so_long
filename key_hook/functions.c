#include "../main.h"
int player_check_col(t_game ****game)
{
	int i;

	i = 0;
	int j;
	while (i < (***game)->k)
	{
		j = 0;
		while ((***game)->arr[i][j] != '\0')
		{
			if ((***game)->arr[i][j] == 'P')
				return j;
			j++;
		}
		i++;
	}
	return j;
}
int player_check_row(t_game ****game)
{
	int i = 0;
	int j;
	while (i < (***game)->k)
	{
		j = 0;
		while ((***game)->arr[i][j] != '\0')
		{
			if ((***game)->arr[i][j] == 'P')
				return i;
			j++;
		}
		i++;
	}
	return i;
}
void lost()
{
	write(1, "WA 3LA KA3KA3\n", 15);
	exit(0);
}
void won()
{
	write(1, "YOU WON\n", 9);
	exit(0);
}

void render_text_on_the_window(t_game ****game)
{
	char *s = ft_itoa((***game)->move_count++);
	(***game)->img = mlx_xpm_file_to_image((***game)->mlx, "./img/wall1.xpm", &(***game)->img_width, &(***game)->img_height);
	mlx_put_image_to_window((***game)->mlx, (***game)->win, (***game)->img, 0, 0);
	mlx_put_image_to_window((***game)->mlx, (***game)->win, (***game)->img, 65, 0);
	mlx_put_image_to_window((***game)->mlx, (***game)->win, (***game)->img, 130, 0);
	mlx_put_image_to_window((***game)->mlx, (***game)->win, (***game)->img, 194, 0);
	mlx_string_put((***game)->mlx, (***game)->win, 0, 0, 0x00FF0000, "move");
	mlx_string_put((***game)->mlx, (***game)->win, 50, 0, 0x00FF0000, s);
}
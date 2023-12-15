#include "../main.h"

int check_right(t_game ***game)
{
	int row; 
	int col;
	
	col = player_check_col(&game);
	row = player_check_row(&game);
	if ((**game)->arr[row][col + 1] == '1')
		return 0;
	else if ((**game)->arr[row][col + 1] == 'M')
		lost();
	else if ((**game)->arr[row][col + 1] == 'E' && (**game)->coins == (**game)->collect)
		won();
	else if (((**game)->arr[row][col + 1] == 'E' && (**game)->coins != (**game)->collect))
		return 0;
	else if ((**game)->arr[row][col + 1] == 'C')
	{
		(**game)->img = mlx_xpm_file_to_image((**game)->mlx, "./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
		mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, (col + 1) * 65, row * 65);
		(**game)->coins++;
	}
	render_text_on_the_window(&game);
	return (1);
}
int check_left(t_game ***game)
{
	int row;
	int col;
	
	col = player_check_col(&game);
	row = player_check_row(&game);
	if ((**game)->arr[row][col - 1] == '1')
		return 0;
	else if ((**game)->arr[row][col - 1] == 'M')
		lost();
	else if ((**game)->arr[row][col - 1] == 'E' && (**game)->coins == (**game)->collect)
		won();
	else if (((**game)->arr[row][col - 1] == 'E' && (**game)->coins != (**game)->collect))
		return 0;
	else if ((**game)->arr[row][col - 1] == 'C')
	{
		(**game)->img = mlx_xpm_file_to_image((**game)->mlx, "./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
		mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, (col - 1) * 65, row * 65);
		(**game)->coins++;
	}
	render_text_on_the_window(&game);
	return (1);
}
int check_down(t_game ***game)
{

	int row = player_check_row(&game);

	int col = player_check_col(&game);

	if ((**game)->arr[row + 1][col] == '1')
		return 0;
	else if ((**game)->arr[row + 1][col] == 'M')
		lost();
	else if ((**game)->arr[row + 1][col] == 'E' && (**game)->coins == (**game)->collect)
		won();
	else if (((**game)->arr[row + 1][col] == 'E' && (**game)->coins != (**game)->collect))
		return 0;
	else if ((**game)->arr[row + 1][col] == 'C')
	{
		(**game)->img = mlx_xpm_file_to_image((**game)->mlx, "./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
		mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, col * 65, (row + 1) * 65);
		(**game)->coins++;
	}
	render_text_on_the_window(&game);
	return (1);
}
int check_up(t_game ***game)
{

	int row = player_check_row(&game);
	int col = player_check_col(&game);
	if ((**game)->arr[row - 1][col] == '1')
		return 0;
	else if ((**game)->arr[row - 1][col] == 'M')
		lost();
	else if ((**game)->arr[row - 1][col] == 'E' && (**game)->coins == (**game)->collect)
		won();
	else if (((**game)->arr[row - 1][col] == 'E' && (**game)->coins != (**game)->collect))
		return 0;
	else if ((**game)->arr[row - 1][col] == 'C')
	{
		(**game)->img = mlx_xpm_file_to_image((**game)->mlx, "./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
		mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, col * 65, (row - 1) * 65);
		(**game)->coins++;
	}
	render_text_on_the_window(&game);
	return (1);
}
#include "../main.h"
void valid_name(char *s)
{
	char ber[] = ".ber";
	int len = ft_strlen(ber) - 1;
	int i = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[i] != ber[len])
		{
			printf("Error");
			exit(0);
		}
		len--;
		i--;
	}
}
int map_check(t_game *game)
{
	if (first_c(game->arr, game->k) == 0)
		return 0;
	if (second_c(game->arr, game->k) == 0)
		return 0;
	if (third_c(&game) == 0)
		return 0;
	return 1;
}
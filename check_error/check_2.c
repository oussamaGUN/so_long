#include "../main.h"
int first_c(char **arr, int k)
{
    int len;
    int i;
	
	i = 1;
	len = ft_strlen_x(arr[0]);
	if (!len)
		return 0;
    while (i < k - 1)
    {
        if (ft_strlen_x(arr[i]) != len)
            return 0;
        i++;
    }
    return 1;
}
int second_c(char **arr,int k)
{
	if (strncmp(arr[0], arr[k - 1], ft_strlen_x(arr[0])) != 0)
		return 0;
	if (strfind(arr[0]) == 0 && strfind(arr[k - 1]) == 0)
		return 0;
	int i = 1;
	while (i < k - 1)
	{
		if (arr[i][0] != arr[i][ft_strlen_x(arr[i]) - 1] && arr[i][ft_strlen_x(arr[i]) - 1] != '1')
			return 0;
		i++;
	}
	return 1;
}

int third_c(t_game **game)
{
	(*game)->count_exit = 0;
	(*game)->garbage = 0;
	positions_check(&game);
	if (!third_c_case((*game)->garbage, (*game)->count_char, (*game)->coin_count, (*game)->count_exit))
		return 0;
	return 1;
}
void positions_check(t_game ***game)
{
	int i;
	int j;
	
	j = 0;
	i = -1;
	while (++i < (**game)->k)
	{
		j = 0;
		while ((**game)->arr[i][j] && (**game)->arr[i][j] != '\n')
		{
			if ((**game)->arr[i][j] == '1' || (**game)->arr[i][j] == '0')
				(**game)->count_wall++;
			else if ((**game)->arr[i][j] == 'P')
				(**game)->count_char++;
			else if ((**game)->arr[i][j] == 'C')
				(**game)->coin_count++;
			else if ((**game)->arr[i][j] == 'E')
				(**game)->count_exit++;
			else if ((**game)->arr[i][j] == 'M')
				(**game)->count_worrior++;
			else
				(**game)->garbage++;
			j++;
		}
	}
}
int third_c_case(int a, int b, int c,int d)
{
	if (a > 0)
		return 0;
	if (b != 1)
		return 0;
	if (d != 1)
		return 0;
	if (c < 1)
		return 0;
	return 1;
}
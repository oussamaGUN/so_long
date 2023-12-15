#include "../main.h"
int strfind(char *arr)
{
	int i;
	
	i = 0;
	while (arr[i] && arr[i] != '\n')
	{
		if (arr[i] != '1')
		{
			return 0;
		}
		i++;
	}
	return 1;
}
int ft_strlen_x(char *s)
{
	int i;
	
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return i;
}


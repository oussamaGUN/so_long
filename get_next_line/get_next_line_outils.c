/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_outils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:56:42 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/16 19:56:52 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s)
		while (s[i] != '\0')
			str[i++] = s[j++];
	j = 0;
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(s) + ft_strlen(buff)] = '\0';
	free(s);
	return (str);
}

int	quit(t_game *game)
{
	(void)game;
	exit(0);
	return (0);
}

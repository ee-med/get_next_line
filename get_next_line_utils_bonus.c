/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hach <mel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:57:38 by mel-hach          #+#    #+#             */
/*   Updated: 2024/02/19 21:40:10 by mel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str && str[len] == '\n')
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*(char *)(p + i) = 0;
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s2 && s2[j] == '\n')
		str[i + j++] = '\n';
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	check_str(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	store_remainder(char *str)
{
	int	i;
	int	new_line_pos;

	i = 0;
	new_line_pos = check_str(str);
	if (new_line_pos >= 0)
	{
		new_line_pos++;
		while (str && str[new_line_pos])
		{
			str[i] = str[new_line_pos];
			i++;
			new_line_pos++;
		}
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
	}
	else
		while (i < BUFFER_SIZE)
			str[i++] = '\0';
}

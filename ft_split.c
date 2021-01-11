/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 03:27:59 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:39:30 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	count;

	i = 0;
	count = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i] == c || s[i + 1] == '\0') && word == 1)
		{
			count++;
			word = 0;
		}
		else if (s[i] != c)
			word = 1;
		i++;
	}
	return (count);
}

static void	ft_strsplit(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (s[start])
	{
		if (s[start] == c)
			start++;
		else
		{
			end = 0;
			while (s[start + end] != c && s[start + end])
				end++;
			if ((dest[i] = ft_substr(s, start, end)))
			{
			}
			i++;
			start += end;
		}
	}
}

char		**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	if (!(dest = (char**)malloc(sizeof(char*) * ft_countwords(s, c) + 1)))
		return (NULL);
	ft_strsplit(dest, s, c);
	dest[ft_countwords(s, c)] = NULL;
	return (dest);
}

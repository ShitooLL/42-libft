/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 01:43:41 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:43:29 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dest = malloc(sizeof(*s) * len + 1)))
		return (NULL);
	if (start >= ft_strlen(s))
		return (dest);
	while (len-- && s[start + i])
	{
		dest[i] = *(s + start + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:22:47 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:41:45 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(dest = ft_strdup(s)))
		return (NULL);
	while (s[i])
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}

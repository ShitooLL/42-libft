/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 01:19:44 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 21:45:09 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s1)
{
	int					i;
	int					neg;
	unsigned long int	nb;

	nb = 0;
	neg = 1;
	i = 0;
	while (s1[i] && (s1[i] == '\t' || s1[i] == '\f' || s1[i] == '\v'
		|| s1[i] == '\n' || s1[i] == '\r' || s1[i] == ' '))
		i++;
	if (s1[i] == '-' || s1[i] == '+')
	{
		if (s1[i] == '-')
			neg = -neg;
		i++;
	}
	while (s1[i] && s1[i] >= '0' && s1[i] <= '9')
	{
		nb = nb * 10 + s1[i] - '0';
		i++;
	}
	if ((nb > LONG_MAX && neg > 0) || (nb - 1) > LONG_MAX)
		nb = (neg > 0) ? 1 : 0;
	return (nb * neg);
}

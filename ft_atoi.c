/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 01:19:44 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 22:20:51 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s1)
{
	int					i;
	int					neg;
	unsigned long int	nb;

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
	nb = 0;
	while (s1[i] && s1[i] >= '0' && s1[i] <= '9')
	{
		nb = nb * 10 + s1[i] - '0';
		i++;
	}
	if ((nb > LONG_MAX && neg > 0) || -nb > LONG_MIN)
		nb = (neg > 0) ? -1 : 0;
	return (nb * neg);
}

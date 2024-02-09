/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:47:05 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/08 22:25:58 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atoi(const char *str)
{
	int					signe;
	long				a;
	int					i;

	a = 0;
	i = 0;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		return (LONG_MAX);
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i++] - '0') * signe;
		if (a > INT_MAX || a < INT_MIN)
			return (LONG_MAX);
	}
	if (str[i])
		return (LONG_MAX);
	return (a);
}

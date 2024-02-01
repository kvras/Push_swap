/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:56:13 by miguiji           #+#    #+#             */
/*   Updated: 2023/11/10 23:42:31 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	long	a;

	a = LONG_MAX;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 && str[i + 1] >=48 && str[i + 1] <= 57)
	{
		signe = signe * -1;
		i++;
	}
	else if (str[i] == 43 && str[i + 1] >=48 && str[i + 1] <= 57)
		i++;
	if (str[i] >= 48 && str[i] <= 57)
		a = 0;
	while (str[i] >= 48 && str[i] <= 57)
		a = a * 10 + str[i++] - 48;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!str[i])
		return (a * signe);
	return (LONG_MAX);
}

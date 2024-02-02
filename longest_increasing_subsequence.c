/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:26:36 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/02 03:03:56 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	initialize(int **len_memoisation, \
int **indices_memoisation, int nums_size)
{
	*len_memoisation = (int *)malloc(sizeof(int) * nums_size);
	if (!*len_memoisation)
		return (-1);
	*indices_memoisation = (int *)malloc(sizeof(int) * nums_size);
	if (!*indices_memoisation)
		return (-1);
	return (1);
}

void	findmax(int *len_memoisation, \
int nums_size, int *max_len, int *max_index)
{
	int	i;

	i = 0;
	while (i < nums_size)
	{
		if (*max_len < len_memoisation[i])
		{
			*max_len = len_memoisation[i];
			*max_index = i;
		}
		i++;
	}
}

int	findfirst(int *indices_memoisation, int *len_memoisation, int nums_size)
{
	int	max_len;
	int	max_index;

	findmax(len_memoisation, nums_size, &max_len, &max_index);
	while (max_len-- > 1)
		max_index = indices_memoisation[max_index];
	return (max_index);
}

void	calculatelis(int *nums, int nums_size, \
int *len_memoisation, int *indices_memoisation)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 1;
	while (x < (nums_size + findfirst(indices_memoisation, \
	len_memoisation, nums_size)))
	{
		indices_memoisation[x % nums_size] = 0;
		len_memoisation[x % nums_size] = 1;
		y = 0;
		while (y < x)
		{
			i = x % nums_size;
			j = y % nums_size;
			if (nums[i] > nums[j] && len_memoisation[i] <= len_memoisation[j])
			{
				len_memoisation[i] = len_memoisation[j] + 1;
				indices_memoisation[i] = j;
			}
			y++;
		}
		x++;
	}
}


int	cleanupandreturn(int *indices_memoisation, int *max_seq, \
	int max_len, int max_index)
{
	int	len;

	len = max_len;
	while (max_len > 0)
	{
		max_seq[--max_len] = max_index;
		max_index = indices_memoisation[max_index];
	}
	free(indices_memoisation);
	return (len);
}

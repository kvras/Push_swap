/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:26:36 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/01 17:38:21 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	initialize(int **len_memoisation, \
int **indices_memoisation, int nums_size)
{
	*len_memoisation = (int *)malloc(sizeof(int) * nums_size);
	*indices_memoisation = (int *)malloc(sizeof(int) * nums_size);
	if (*len_memoisation == NULL || *indices_memoisation == NULL)
		return (-1);
	return (1);
}

void	calculatelis(int *nums, int nums_size, \
int *len_memoisation, int *indices_memoisation)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	first = 0;

	x = 0;
	while (x < nums_size + first % nums_size)
	{
		indices_memoisation[x] = -1;
		len_memoisation[x] = 1;
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

int	lis(int *nums, int nums_size, int *max_seq)
{
	int	*len_memoisation;
	int	*indices_memoisation;
	int	max_len;
	int	max_index;

	max_len = 0;
	max_index = 0;
	if (initialize(&len_memoisation, \
	&indices_memoisation, nums_size) == -1)
		return (-1);
	calculatelis(nums, nums_size, len_memoisation, indices_memoisation);
	findmax(len_memoisation, nums_size, &max_len, &max_index);
	free(len_memoisation);
	return (cleanupandreturn (indices_memoisation, max_seq, max_len, max_index));
}
// int lis(int* nums, int numsSize, int* maxSeq)
// {
//     int *len_memoisation;
//     int temp;
//     int *indices_memoisation;
//     int first = 0;
//     int i=0,j = 0,x = 0,y = 0,max_len = 0,max_index = 0;
//     len_memoisation = (int *)malloc(sizeof(int)*numsSize);
//     if(len_memoisation == NULL)
//         return -1;
//     indices_memoisation = (int *)malloc(sizeof(int)*numsSize);
//     if(indices_memoisation == NULL)
//         return -1;
//     while(x < numsSize+ first%numsSize)
//     {
//         indices_memoisation[x%numsSize] = -1;
//         len_memoisation[x%numsSize] = 1;
//         y = 0;
//         while(y < x)
//         {
//             i = x%numsSize;
//             j = y%numsSize;
//             if(nums[i]>nums[j] && len_memoisation[i]<=len_memoisation[j])
//             {
//                 len_memoisation[i] = len_memoisation[j] + 1;
//                 indices_memoisation[i] = j;   // we store the index of the previous element in the index of the current element
//                                               // we save thim by indices not the lenghts to avoid the problem of overwriting
//                                               // so that each index have its own previous index
//             }
//             if(max_len < len_memoisation[i])
//             {
//                 max_len = len_memoisation[i];
//                 max_index = i;       // we store max_index because ther is no way to find it later
//                 temp = max_index;
//                 for(int count = 1; count < max_len; count++)
//                     temp = indices_memoisation[temp];
//                 first = temp;       // we store the first indice of the max_len
//             }
//             y++;
//         }
//         x++;
//     }
//      //printf("first indice is = %d\n",first);
//     i = max_len;
//     temp = max_index;    // we start from the end of the array and go back to the beginning using the indices_memoisation array
//                              // we start with max_index because it is the key to fuind other indices
//     while(i > 0)
//     {
//         maxSeq[--i] = temp;
//         temp = indices_memoisation[temp];    // we replace the current index in the array to get his matching index
//     }
//     free(len_memoisation);
//     free(indices_memoisation);
//     return max_len;
// }
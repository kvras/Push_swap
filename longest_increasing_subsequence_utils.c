/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:04:17 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/02 04:30:50 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
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
	return (cleanupandreturn (indices_memoisation, \
		max_seq, max_len, max_index));
}

void	lis_filter(t_stack *stack_a, t_stack *stack_b, int *sequence, int len)
{
	int	count;
	int	size;

	count = 0;
	size = stack_a->size;
	while (count < size)
	{
		if (search(sequence, len, count))
		{
			ra(stack_a);
			ft_printf("ra\n");
			count++;
			continue ;
		}
		pb(stack_a, stack_b);
		ft_printf("pb\n");
		count++;
	}
}

int	longest_increasing_subsequence_caller(t_stack *stack_a,
	t_stack *stack_b, int argc, char **argv)
{
	int		i;
	int		len;
	int		*sequence;
	int		*instence;
	t_node	*temp_stack_a;

	if (parsing(argc, argv, stack_a) == 0)
		return (0);
	instence = (int *)malloc((stack_a->size) * 4);
	sequence = (int *)malloc((stack_a->size) * 4);
	if (!instence || !sequence)
		return (free(instence), free(sequence), 0);
	i = 0;
	temp_stack_a = stack_a->top;
	while (temp_stack_a)
	{
		instence[i++] = temp_stack_a->data;
		temp_stack_a = temp_stack_a->next;
	}
	len = lis(instence, stack_a->size, sequence);
	if (len == -1)
		return (0);
	lis_filter(stack_a, stack_b, sequence, len);
	push_back(stack_a, stack_b);
	return (free(instence), free(sequence), 1);
}

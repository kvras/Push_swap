/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:04:17 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/04 00:18:42 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_of_5(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*temp_stack_a;

// 	temp_stack_a = stack_a->top;
// 	pb(stack_a, stack_b);
// 	pb(stack_a, stack_b);
// 	ft_printf("pb\npb\n");
// 	if(temp_stack_a->data > temp_stack_a->next->data)
// 	{
// 		sa(stack_a);
// 		ft_printf("sa\n");
// 	}
// }

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
	int		*sequence;
	int		*instence;
	t_node	*temp_stack_a;

	if (parsing(argc, argv, stack_a, 0) == 0)
		return (0);
	// if (stack_a->size == 5)
	// 	return(sort_of_5(stack_a, stack_b),push_back(stack_a, stack_b), 1);
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
	i = lis(instence, stack_a->size, sequence);
	if (i == -1)
		return (free(instence), free(sequence), 0);
	lis_filter(stack_a, stack_b, sequence, i);
	return (push_back(stack_a, stack_b), free(instence), free(sequence), 1);
}

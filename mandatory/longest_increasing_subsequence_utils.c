/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:04:17 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/08 20:00:08 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_of_3(t_stack *a)
{
	if (a->top->data < a->top->next->data && a->top->next->data
		> a->top->next->next->data)
	{
		sa(a);
		ft_printf("sa\n");
	}
	if (a->top->data > a->top->next->data && a->top->data
		> a->top->next->next->data)
	{
		ra(a);
		ft_printf("ra\n");
	}
	if (a->top->data > a->top->next->data)
	{
		sa(a);
		ft_printf("sa\n");
	}
	if (a->top->next->next->data < a->top->next->data
		&& a->top->next->next->data < a->top->data)
	{
		rra(a);
		ft_printf("rra\n");
	}
}

void	sort_of_5(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = a->top;
	if (a->size == 5)
	{
		while (temp->next)
		{
			if (temp->data > temp->next->data)
			{
				pb(a, b);
				pb(a, b);
				ft_printf("pb\npb\n");
				break ;
			}
			temp = temp->next;
		}
	}
	sort_of_3(a);
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

int	check_if_sorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	lis_filter(t_stack *stack_a, t_stack *stack_b, int *sequence, int len)
{
	int		count;
	int		size;

	count = 0;
	size = stack_a->size;
	if (check_if_sorted(stack_a) == 1)
		return ;
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

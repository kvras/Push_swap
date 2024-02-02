/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence_caller.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:16:38 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/02 04:34:30 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	execute(t_stack *stack_a, t_stack *stack_b, t_best_move *best_move)
{
	if (best_move->metric == 1)
	{
		r_handler_a(stack_a, best_move->position_a, best_move->size_a);
		r_handler_b(stack_b, best_move->position_b, best_move->size_b);
		pa(stack_a, stack_b);
		printf("pa\n");
	}
	else if (best_move->metric == 2)
		rr_handler(stack_a, stack_b, best_move);
	else
		rrr_handler(stack_a, stack_b, best_move);
}

int	get_matching_index(t_node *temp, int data, int min_value, int max_value)
{
	int		i;
	int		max_value_index;
	int		min_value_index;

	max_value_index = 0;
	i = 0;
	min_value_index = -1;
	while (temp)
	{
		if (data < temp->data && temp->data < min_value)
		{
			min_value = temp->data;
			min_value_index = i;
		}
		if (temp->data < max_value)
		{
			max_value = temp->data;
			max_value_index = i;
		}
		i++;
		temp = temp->next;
	}
	if (min_value_index == -1)
		min_value_index = max_value_index;
	return (min_value_index);
}

void	rotater(t_stack *stack_a)
{
	int		count_a;
	t_node	*temp_top_a;
	int		min_value;
	int		index;

	min_value = INT_MAX;
	temp_top_a = stack_a->top;
	count_a = 0;
	while (temp_top_a)
	{
		if (temp_top_a->data < min_value)
		{
			min_value = temp_top_a->data;
			index = count_a;
		}
		temp_top_a = temp_top_a->next;
		count_a++;
	}
	r_handler_a(stack_a, index, stack_a->size);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	t_best_move	best_move;
	t_node		*temp_top_b;
	int			count_b;
	int			count_a;

	while (stack_b->size > 0)
	{
		best_move.cost = INT_MAX;
		temp_top_b = stack_b->top;
		count_b = 0;
		while (temp_top_b)
		{
			count_a = get_matching_index(stack_a->top,
					temp_top_b->data, INT_MAX, INT_MAX);
			best_move.size_a = stack_a->size;
			best_move.size_b = stack_b->size;
			calculator(count_a, count_b, &best_move, 0);
			count_b++;
			temp_top_b = temp_top_b->next;
		}
		execute(stack_a, stack_b, &best_move);
	}
	rotater(stack_a);
}

void	calculator(int count_a, int count_b, t_best_move *best_move, int rrr)
{
	int	cost;
	int	metric;
	int	r;
	int	rr;

	r = min((best_move->size_b - count_b), count_b)
		+ min((best_move->size_a - count_a), count_a);
	rr = max(count_b, count_a);
	rrr = max(best_move->size_b - count_b, best_move->size_a - count_a);
	cost = min(r, min(rr, rrr));
	metric = set(r, rr, rrr, cost);
	if (cost < best_move->cost)
	{
		best_move->metric = metric;
		best_move->cost = cost;
		best_move->position_a = count_a;
		best_move->position_b = count_b;
	}
}

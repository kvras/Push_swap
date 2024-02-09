/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methodes_3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:13:32 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/10 00:01:17 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	rra(t_stack *stack_a)
{
	t_node	*temp;
	t_node	*befor_last_element;

	if (stack_a->size <= 1)
		return ;
	temp = stack_a->top;
	while (temp->next)
	{
		befor_last_element = temp;
		temp = temp->next;
	}
	befor_last_element->next = NULL;
	stack_a->bottom->next = stack_a->top;
	stack_a->top = stack_a->bottom;
	stack_a->bottom = befor_last_element;
}

void	rrb(t_stack *stack_b)
{
	rra(stack_b);
}

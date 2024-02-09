/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methodes_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:13:40 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/09 23:58:14 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->size <= 1)
		return ;
	temp = stack_a->top->next;
	stack_a->top->next = stack_a->top->next->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
}

void	sb(t_stack *stack_b)
{
	sa(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->size <= 1)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->bottom->next = temp;
	temp->next = NULL;
	stack_a->bottom = temp;
}

void	rb(t_stack *stack_b)
{
	ra(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methodes_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:13:40 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/04 00:18:42 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->top->next;
	stack_a->top->next = stack_a->top->next->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
}

void	sb(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return ;
	sa(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	sa(stack_a);
	sb(stack_b);
}

void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->size < 1)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->bottom->next = temp;
	temp->next = NULL;
	stack_a->bottom = temp;
}

void	rb(t_stack *stack_b)
{
	if (stack_b->size < 1)
		return ;
	ra(stack_b);
}

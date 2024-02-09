/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methodes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:13:28 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/04 00:55:48 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	push(t_stack *t_stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (ft_printf("Error"), 0);
	new_node->next = NULL;
	new_node->data = data;
	if (t_stack->top)
	{
		new_node->next = t_stack->top;
		t_stack->top = new_node;
	}
	else
	{
		t_stack->top = new_node;
		t_stack->bottom = new_node;
	}
	return (t_stack->size++, 1);
}

t_node	*pop(t_stack *stack)
{
	t_node	*popped;

	if (!stack->top)
		return (NULL);
	popped = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	return (popped);
}

int	is_empty(t_stack *t_stack)
{
	return (t_stack->size <= 0);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_b) != 1)
	{
		if (!push(stack_a, stack_b->top->data))
		{
			ft_printf("Error");
			return ;
		}
		free(pop(stack_b));
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a) != 1)
	{
		if (!push(stack_b, stack_a->top->data))
		{
			ft_printf("Error");
			return ;
		}
		free(pop(stack_a));
	}
}

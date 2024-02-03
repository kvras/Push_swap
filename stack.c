/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 04:47:12 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/04 00:18:42 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_a->top = NULL;
	stack_b->top = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->bottom = NULL;
	stack_b->bottom = NULL;
	if (argc > 1)
	{
		if (!longest_increasing_subsequence_caller(stack_a,
				stack_b, argc, argv))
		{
			ft_printf("Error\n");
			return (free(stack_a), free(stack_b), 0);
		}
	}
	free(stack_a);
	free(stack_b);
	return (0);
}

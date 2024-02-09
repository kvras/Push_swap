/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 04:47:12 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/08 19:53:55 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	free_stack(t_stack *stack)
{
	while (stack->top)
		free(pop(stack));
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
	if (stack_a->size == 5 || stack_a->size == 3)
		return (sort_of_5(stack_a, stack_b), push_back(stack_a, stack_b), 1);
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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.top = NULL;
	stack_b.top = NULL;
	stack_a.size = 0;
	stack_b.size = 0;
	stack_a.bottom = NULL;
	stack_b.bottom = NULL;
	if (argc > 1)
	{
		if (!longest_increasing_subsequence_caller(&stack_a,
				&stack_b, argc, argv))
		{
			ft_printf("Error\n");
			return (free_stack(&stack_a), free_stack(&stack_b), 0);
		}
	}
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}

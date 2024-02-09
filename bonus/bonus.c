/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:58:21 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/08 19:41:31 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	stack_check(t_stack *stack_a, int *tab)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack_a->top;
	while (temp)
	{
		if (tab[i++] != temp->data)
			return (write(1, "KO\n", 3), 0);
		temp = temp->next;
	}
	return (write(1, "OK\n", 3), 1);
}

void	free_stack(t_stack *stack)
{
	while (stack->top)
		free(pop(stack));
}

char	*get_next_line_caller(char **line)
{
	free(*line);
	*line = NULL;
	*line = get_next_line(0);
	return (*line);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	stack_a;
	t_stack	stack_b;
	int		*tab;

	stack_a.top = NULL;
	stack_a.bottom = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.bottom = NULL;
	stack_b.size = 0;
	if (!parsing(argc, argv, &stack_a, 0) || argc == 1)
		return (write(1, "Error\n", 6), free_stack(&stack_a), 0);
	tab = (int *)malloc(sizeof(int) * stack_a.size);
	init_sort_array(&stack_a, tab);
	line = NULL;
	while (get_next_line_caller(&line))
	{
		if (!apply_operation(line, &stack_a, &stack_b))
			return (free(line), free(tab),
				free_stack(&stack_a), free_stack(&stack_b), 0);
	}
	return (stack_check(&stack_a, tab), free_stack(&stack_a),
		free_stack(&stack_b), free(tab), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:53:08 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/04 00:18:42 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set(int r, int rr, int rrr, int cost)
{
	if (r == cost)
		return (1);
	if (rr == cost)
		return (2);
	if (rrr == cost)
		return (3);
	return (0);
}

void	r_handler_a(t_stack *stack_a, int position_a, int size_a)
{
	int	i;

	i = 0;
	if (position_a < (size_a - position_a))
	{
		while (position_a - i)
		{
			ra(stack_a);
			ft_printf("ra\n");
			i++;
		}
		return ;
	}
	while ((size_a - position_a - i) > 0)
	{
		rra(stack_a);
		ft_printf("rra\n");
		i++;
	}
}

void	r_handler_b(t_stack *stack_b, int position_b, int size_b)
{
	int	i;

	i = 0;
	if (position_b < (size_b - position_b))
	{
		while (position_b - i)
		{
			ra(stack_b);
			ft_printf("rb\n");
			i++;
		}
		return ;
	}
	while (size_b - position_b - i)
	{
		rra(stack_b);
		ft_printf("rrb\n");
		i++;
	}
}

int	rr_handler(t_stack *stack_a, t_stack *stack_b, t_best_move *best_move)
{
	int	i;

	i = 0;
	while (i < min(best_move->position_a, best_move->position_b))
	{
		rr(stack_a, stack_b);
		ft_printf("rr\n");
		i++;
	}
	i = 0;
	if (best_move->position_a < best_move->position_b)
	{
		while (best_move->position_b - best_move->position_a -(i++))
		{
			rb(stack_b);
			ft_printf("rb\n");
		}
		return (pa(stack_a, stack_b), ft_printf("pa\n", 0));
	}
	while (best_move->position_a - best_move->position_b -(i++))
	{
		ra(stack_a);
		ft_printf("ra\n");
	}
	return (pa(stack_a, stack_b), ft_printf("pa\n", 0));
}

int	rrr_handler(t_stack *stack_a, t_stack *stack_b, t_best_move *b)
{
	int	i;

	i = 0;
	while (i < min(b->size_a - b->position_a, b->size_b - b->position_b))
	{
		rrr(stack_a, stack_b);
		ft_printf("rrr\n");
		i++;
	}
	i = 0;
	if (b->size_a - b->position_a < b->size_b - b->position_b)
	{
		while (b->size_b - b->position_b - b->size_a + b->position_a - (i++))
		{
			rrb(stack_b);
			ft_printf("rrb\n");
		}
		return (pa(stack_a, stack_b), ft_printf("pa\n", 0));
	}
	while (b->size_a - b->position_a - b->size_b + b->position_b - (i++))
	{
		rra(stack_a);
		ft_printf("rra\n");
	}
	return (pa(stack_a, stack_b), ft_printf("pa\n", 0));
}

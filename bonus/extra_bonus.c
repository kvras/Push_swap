/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:18:28 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/04 00:26:44 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *str1, char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i])
		return (s1[i]);
	else if (s2[i])
		return (-s2[i]);
	return (0);
}

void	sort_int_tab(int *tab)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (tab[i] < tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	apply_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		return (write(1, "Error\n", 6), 0);
	return (1);
}

void	init_sort_array(t_stack *stack_a, int *tab)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack_a->top;
	while (i < stack_a->size)
	{
		tab[i++] = temp->data;
		temp = temp->next;
	}
	sort_int_tab(tab);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:58:55 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/08 18:47:15 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_stack *stack_a)
{
	t_node	*temp;
	t_node	*temp2;

	temp = stack_a->top;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->data == temp2->data)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	parsing(int argc, char **argv, t_stack *stack_a, int i)
{
	char	**temp;
	int		x;

	temp = NULL;
	while ((argc - (++i)) > 0)
	{
		x = 0;
		free_arr(temp);
		temp = ft_split(argv[argc - i], ' ');
		if (!temp[x])
			return (free_arr(temp), 0);
		while (temp[x])
			x++;
		while (x-- > 0)
		{
			if ((ft_atoi(temp[x]) <= INT_MAX) && (ft_atoi(temp[x]) >= INT_MIN))
			{
				push(stack_a, (int)ft_atoi(temp[x]));
				if (checker(stack_a) == 0)
					continue ;
			}
			return (free_arr(temp), 0);
		}
	}
	return (free_arr(temp), 1);
}

int	search(int *array, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == number)
			return (1);
		i++;
	}
	return (0);
}

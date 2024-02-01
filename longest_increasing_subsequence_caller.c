/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence_caller.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:16:38 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/01 17:39:10 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	checker(stack *stack)
{
	node	*temp;
	node	*temp2;

	temp = stack->top;
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

int	parsing(int argc, char **argv, stack *stack_a)
{
	int		i;
	char	**temp;
	int		x;

	i = 0;
	while ((argc - (++i)) > 0)
	{
		x = 0;
		temp = ft_split(argv[argc - i], ' ');
		if (!temp[x])
			return (0);
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
			return (0);
		}
		free(temp);
		temp = NULL;
	}
	return (1);
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

void	lis_filter(stack *stack_a, stack *stack_b, int *sequence, int len)
{
	int	count;
	int	size;

	count = 0;
	size = stack_a->size;
	while (count < size)
	{
		if (search(sequence, len, count))
		{
			ra(stack_a);
			ft_printf("ra\n");
			count++;
			continue ;
		}
		pb(stack_a, stack_b);
		ft_printf("pb\n");
		count++;
	}
}

int	longest_increasing_subsequence_caller(stack *stack_a, \
	stack *stack_b, int argc, char **argv)
{
	int		i;
	int		len;
	int		*sequence;
	int		*instence;
	node	*temp_stack_a;

	if (parsing(argc, argv, stack_a) == 0)
		return (0);
	instence = (int *)malloc((stack_a->size) * 4);
	sequence = (int *)malloc((stack_a->size) * 4);
	if (!instence || !sequence)
		return (0);
	i = 0;
	temp_stack_a = stack_a->top;
	while (temp_stack_a)
	{
		instence[i++] = temp_stack_a->data;
		temp_stack_a = temp_stack_a->next;
	}
	len = lis(instence, stack_a->size, sequence);
	if (len == -1)
		return (0);
	lis_filter(stack_a, stack_b, sequence, len);
	//print_stack(stack_a);
	push_back(stack_a, stack_b);
	free(sequence);
	free(instence);
	return (1);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void r_handler_a(stack *stack_a, int position_a, int size_a)
{
	int	i;

	i = 0;
	if (position_a < (size_a - position_a))
	{
		while (position_a - i)
		{
			ra(stack_a);
			printf("ra\n");
			i++;
		}
		return ;
	}
	while ((size_a - position_a - i) > 0)
	{
		rra(stack_a);
		printf("rra\n");
		i++;
	}
}

void r_handler_b(stack *stack_b, int position_b, int size_b)
{
	int	i;

	i = 0;
	if (position_b < (size_b - position_b))
	{
		while (position_b - i)
		{
			ra(stack_b);
			printf("rb\n");
			i++;
		}
		return ;
	}
	while (size_b - position_b - i)
	{
		rra(stack_b);
		printf("rrb\n");
		i++;
	}
}

void	rr_handler(stack *stack_a, stack *stack_b, best_move *best_move)
{
	int	i;

	i = 0;
	while (i < min(best_move->position_a, best_move->position_b))
	{
		rr(stack_a, stack_b);
		printf("rr\n");
		i++;
	}
	i = 0;
	if (best_move->position_a < best_move->position_b)
	{
		while (best_move->position_b - best_move->position_a -(i++))
		{
			rb(stack_b);
			printf("rb\n");
		}
		pa(stack_a, stack_b);
		printf("pa\n");
		return ;
	}
	while (best_move->position_a - best_move->position_b -(i++))
	{
		ra(stack_a);
		printf("ra\n");
	}
	pa(stack_a, stack_b);
	printf("pa\n");
}

void	rrr_handler(stack *stack_a, stack *stack_b, best_move *best_move)
{
	int	i;

	i = 0;
	while (i < min(best_move->size_a - best_move->position_a, best_move->size_b - best_move->position_b))
	{
		rrr(stack_a, stack_b);
		printf("rrr\n");
		i++;
	}
	i = 0;
	if (best_move->size_a - best_move->position_a < best_move->size_b - best_move->position_b)
	{
		while (best_move->size_b - best_move->position_b-best_move->size_a + best_move->position_a-(i++))
		{
			rrb(stack_b);
			printf("rrb\n");
		}
		pa(stack_a, stack_b);
		printf("pa\n");
		return;
	}
	while (best_move->size_a - best_move->position_a-best_move->size_b + best_move->position_b-(i++))
	{
		rra(stack_a);
		printf("rra\n");
	}
	pa(stack_a, stack_b);
	printf("pa\n");
}

void execute(stack *stack_a, stack *stack_b, best_move *best_move)
{
	if (best_move->metric == 1)
	{
		r_handler_a(stack_a, best_move->position_a, best_move->size_a);
		r_handler_b(stack_b, best_move->position_b, best_move->size_b);
		pa(stack_a, stack_b);
		printf("pa\n");
	}
	else if (best_move->metric == 2)
		rr_handler(stack_a, stack_b, best_move);
	else
		rrr_handler(stack_a, stack_b, best_move);
}

// int	get_matching_index(stack *stack_a, int data)
// {
// 	node	*temp;
// 	int		i;
// 	int		min_value;
// 	int		max_value;
// 	int		max_value_index;
// 	int		min_value_index;

// 	i = 0;
// 	min_value = INT_MAX;
// 	max_value = INT_MIN;
// 	temp = stack_a->top;
// 	min_value_index = -1;
// 	while (temp)
// 	{
// 		if (data < temp->data && temp->data < min_value)
// 		{
// 			min_value = temp->data;
// 			min_value_index = i;
// 		}
// 		if (temp->data < max_value)
// 		{
// 			max_value = temp->data;
// 			max_value_index = i;
// 		}
// 		i++;
// 		temp = temp->next;
// 	}
// 	if (min_value_index == -1)
// 		min_value_index = max_value_index;
// 	return (min_value_index);
// }
int get_matching_index(stack *stack_a, int data)
{
    node *temp = stack_a->top;
    int i = 0;
    int min_value = INT_MAX;
    int max_value = INT_MAX;
    int max_value_index = 0;
    int min_value_index;
    min_value_index = -1;
    while(temp)
    {
        if(data < temp->data && temp->data < min_value)
        {
            min_value = temp->data;
            min_value_index = i;
        }
        if(temp->data < max_value)
        {
            max_value = temp->data;
            max_value_index = i;
        }
        i++;
        temp = temp->next;
    }
    if(min_value_index == -1)
        min_value_index = max_value_index;
    return min_value_index;
}

void print_stack(stack *stack)
{
	int		i;
	node	*temp;

	i = 0;
	temp = stack->top;
	while (temp)
	{
		printf("|%d| %d \n", i, temp->data);
		temp = temp->next;
		i++;
	}
}
void	rotater(stack *stack_a)
{
	int		count_a;
	node	*temp_top_a;
	int		min_value;
	int		index;

	min_value = INT_MAX;
	temp_top_a = stack_a->top;
	count_a = 0;
	while (temp_top_a)
	{
		if (temp_top_a->data < min_value)
		{
			min_value = temp_top_a->data;
			index = count_a;
		}
		temp_top_a = temp_top_a->next;
		count_a++;
	}
	r_handler_a(stack_a, index, stack_a->size);
}

void push_back(stack *stack_a, stack *stack_b)
{
	best_move	best_move;
	node		*temp_top_b;
	int			count_b;
	int			count_a;

	while (stack_b->size > 0)
	{
		best_move.cost = INT_MAX;
		temp_top_b = stack_b->top;
		count_b = 0;
		while (temp_top_b)
		{
			count_a = get_matching_index(stack_a, temp_top_b->data);
			best_move.size_a = stack_a->size;
			best_move.size_b = stack_b->size;
			calculator(count_a, count_b, &best_move, 0);
			count_b++;
			temp_top_b = temp_top_b->next;
		}
		// printf("position a = %d position b = %d metric = %d\n", best_move.position_a,best_move.position_b, best_move.metric);
		// puts("------------------");
		// print_stack(stack_a);
		// puts("------------------");
		// print_stack(stack_b);
		// puts("------------------");
		// puts("------------------");
		execute(stack_a, stack_b, &best_move);
	}
	rotater(stack_a);
}

int set(int r, int rr, int rrr, int cost)
{
	if (r == cost)
		return (1);
	if (rr == cost)
		return (2);
	if (rrr == cost)
		return (3);
	return (0);
}

void calculator(int count_a, int count_b, best_move *best_move,int rrr)
{
	int	cost;
	int	metric;
	int	r;
	int	rr;

	r = min((best_move->size_b - count_b), count_b) + min((best_move->size_a - count_a), count_a);
	rr = max(count_b, count_a);
	rrr = max(best_move->size_b - count_b, best_move->size_a - count_a);
	cost = min(r, min(rr, rrr));
	metric = set(r, rr, rrr, cost);
	if (cost < best_move->cost)
	{
		best_move->metric = metric;
		best_move->cost = cost;
		best_move->position_a = count_a;
		best_move->position_b = count_b;
	}
}

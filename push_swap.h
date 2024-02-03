/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 04:45:01 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/03 19:23:38 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line.h"
# include "printf/libftprintf.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int			size;
	t_node		*top;
	t_node		*bottom;
}	t_stack;

typedef struct s_best_move
{
	int	position_b;
	int	position_a;
	int	size_a;
	int	size_b;
	int	metric;
	int	cost;
}	t_best_move;

long	ft_atoi(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	**ft_split(char *original, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		lis(int *nums, int numsSize, int *maxSeq);
int		push(t_stack *stack, int data);
t_node	*pop(t_stack *stack);
int		is_empty(t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		search(int *array, int size, int number);
void	lis_filter(t_stack *stack_a, t_stack *stack_b, int *sequence, int len);
int		longest_increasing_subsequence_caller(t_stack *stack_a,
			t_stack *stack_b, int argc, char **argv);
void	push_back(t_stack *stack_a, t_stack *stack_b);
int		set(int r, int rr, int rrr, int cost);
void	calculator(int count_a, int count_b, t_best_move *best_move, int rrr);
void	execute(t_stack *stack_a, t_stack *stack_b, t_best_move *best_move);
int		min(int a, int b);
int		max(int a, int b);
void	r_handler_a(t_stack *stack_a, int position_a, int size_a);
void	r_handler_b(t_stack *stack_b, int position_b, int size_b);
int		rr_handler(t_stack *stack_a, t_stack *stack_b, t_best_move *best_move);
int		rrr_handler(t_stack *stack_a, t_stack *stack_b, t_best_move *best_move);
int		get_matching_index(t_node *top, int data, int min, int max);
void	rotater(t_stack *stack_a);
int		cleanupandreturn(int *indices_memoisation,
			int *max_seq, int max_len, int max_index);
void	calculatelis(int *nums, int nums_size,
			int *len_memoisation, int *indices_memoisation);
void	findmax(int *len_memoisation, int nums_size,
			int *max_len, int *max_index);
int		parsing(int argc, char **argv, t_stack *stack_a, int i);
int		initialize(int **len_memoisation,
			int **indices_memoisation, int nums_size);
#endif
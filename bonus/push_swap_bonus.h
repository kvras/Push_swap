/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:48:51 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/08 20:07:20 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line.h"
# include "../printf/libftprintf.h"

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

long	ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*get_next_line(int fd);
int		push(t_stack *stack, int data);
t_node	*pop(t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		is_empty(t_stack *stack);
int		checker(t_stack *stack);
int		parsing(int argc, char **argv, t_stack *stack_a, int i);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	**ft_split(char *original, char c);
void	init_sort_array(t_stack *stack_a, int *tab);
int		apply_operation(char *line, t_stack *stack_a, t_stack *stack_b);
int		ft_strcmp(char *str1, char *str2);
void	free_stack(t_stack *stack);
int		stack_check(t_stack *stack_a, int *tab);
char	*get_next_line_caller(char **line);
int		max(int a, int b);
void	free_arr(char **arr);

#endif
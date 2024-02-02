#include "header.h"

int push(t_stack *t_stack, int data)
{
	t_node *new_t_node;
	new_t_node = (t_node *)malloc(sizeof(t_node));
	if (!new_t_node)
	{
		ft_printf("Error");
		return 0;
	}
	new_t_node->next = NULL;
	new_t_node->data = data;
	if (t_stack->top)
	{
		new_t_node->next = t_stack->top;
		t_stack->top = new_t_node;
	}
	else
	{
		t_stack->top = new_t_node;
		t_stack->bottom = new_t_node;
	}
	t_stack->size++;
	return 1;
}
t_node *pop(t_stack *t_stack)
{
	t_node *popped;
	if (!t_stack->top)
		return NULL;
	popped = t_stack->top;
	t_stack->top = t_stack->top->next;
	t_stack->size--;
	return popped;
}
int is_empty(t_stack *t_stack)
{
	return (t_stack->size <= 0);
}
void pa(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_b) != 1)
	{
		if (!push(stack_a, stack_b->top->data))
		{
			ft_printf("Error");
			return;
		}
		free(pop(stack_b));
	}
}
void pb(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a) != 1)
	{
		if (!push(stack_b, stack_a->top->data))
		{
			ft_printf("Error");
			return;
		}
		free(pop(stack_a));
	}
}
void sa(t_stack *stack_a)
{
	t_node *temp = stack_a->top->next;
	stack_a->top->next = stack_a->top->next->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
}
void sb(t_stack *stack_b)
{
	sa(stack_b);
}
void Ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
void ra(t_stack *stack_a)
{
	t_node *temp;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->bottom->next = temp;
	temp->next = NULL;
	stack_a->bottom = temp;
}
void rb(t_stack *stack_b)
{
	ra(stack_b);
}
void rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
void rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
void rra(t_stack *stack_a)
{
	t_node *temp;
	t_node *befor_last_element;
	temp = stack_a->top;
	while (temp->next)
	{
		befor_last_element = temp;
		temp = temp->next;
	}
	befor_last_element->next = NULL;
	stack_a->bottom->next = stack_a->top;
	stack_a->top = stack_a->bottom;
	stack_a->bottom = befor_last_element;
}
void rrb(t_stack *stack_b)
{
	rra(stack_b);
}
void print_t_stack(t_stack *t_stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = t_stack->top;
	while (temp)
	{
		printf("|%d| %d \n", i, temp->data);
		temp = temp->next;
		i++;
	}
}

int main(int argc, char **argv)
{

	if (argc > 1)
	{
		t_stack *stack_a = (t_stack *)malloc(sizeof(t_stack));
		t_stack *stack_b = (t_stack *)malloc(sizeof(t_stack));
		stack_a->top = NULL;
		stack_b->top = NULL;
		stack_a->size = 0;
		stack_b->size = 0;
		stack_a->bottom = NULL;
		stack_b->bottom = NULL;
		if (!longest_increasing_subsequence_caller(stack_a, stack_b, argc, argv))
		{
			ft_printf("Error\n");
			return (free(stack_a),free(stack_b),0);
		}
		free(stack_a);
		free(stack_b);
	}
	return (0);
}

#include "header.h"

int checker(t_stack *t_stack)
{
    t_node *temp;
    t_node *temp2;
    temp = t_stack->top;
    while (temp)
    {
        temp2 = temp->next;
        while (temp2)
        {
            if (temp->data == temp2->data)
                return 1;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return 0;
}
int parsing(int argc, char **argv, t_stack *stack_a)
{
    int i;
    char **temp;
    int x;
    i = 0;
    while ((argc-(++i)) >0)
    {
        x = 0;
        temp = ft_split(argv[argc-i], ' ');
        if (!temp[x])
            return (0);
        while (temp[x])
            x++;
        while (x-- >0)
        {
            if ((ft_atoi(temp[x]) <= INT_MAX) && (ft_atoi(temp[x]) >= INT_MIN))
            {
                push(stack_a,(int)ft_atoi(temp[x]));
                if (checker(stack_a) == 0)
                    continue;
            }
            return (0);
        }
        free(temp);
        temp = NULL;
    }
    return (1);
}
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
void push(t_stack *t_stack, int data)
{
    t_node *new_t_node;
    new_t_node = (t_node *)malloc(sizeof(t_node));
    if (!new_t_node)
        return;
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
}
t_node *pop(t_stack *t_stack)
{
    t_node *popped;
    if (!t_stack->top)
    {
        puts("the t_stack is empty");
        return NULL;
    }
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
        push(stack_a, stack_b->top->data);
        free(pop(stack_b));
    }
}
void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (is_empty(stack_a) != 1)
    {
        push(stack_b, stack_a->top->data);
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
void print_t_stack(t_stack *t_stack)
{
    int i = 0;
    t_node *temp = t_stack->top;
    while (temp)
    {
        printf("|%d| %d \n",i,temp->data);
        temp = temp->next;
        i++;
    }
}
void ss(t_stack *stack_a, t_stack *stack_b)
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
void sort_int_tab(int *tab)
{
    int i;
    int j;
    int temp;
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
int apply_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
    if (!ft_strcmp(line,"sa"))
        sa(stack_a);
    else if (!ft_strcmp(line,"sb\n"))
        sb(stack_b);
    else if (!ft_strcmp(line,"ss\n"))
        ss(stack_a, stack_b);
    else if (!ft_strcmp(line,"pa\n"))
        pa(stack_a, stack_b);
    else if (!ft_strcmp(line,"pb\n"))
        pb(stack_a, stack_b);
    else if (!ft_strcmp(line,"ra\n"))
        ra(stack_a);
    else if (!ft_strcmp(line,"rb\n"))
        rb(stack_b);
    else if (!ft_strcmp(line,"rr\n"))
        rr(stack_a, stack_b);
    else if (!ft_strcmp(line,"rra\n"))
        rra(stack_a);
    else if (!ft_strcmp(line,"rrb\n"))
        rrb(stack_b);
    else if (!ft_strcmp(line,"rrr\n"))
        rrr(stack_a, stack_b);
    else
        return (write(1,"Error\n",6),0);
    return 1;
}
void init_sort_array(t_stack *stack_a, int *tab)
{
    int i;
    t_node *temp;
    i = 0;
    temp = stack_a->top;
    while (i<stack_a->size)
    {
        tab[i++] = temp->data;
        temp = temp->next;
    }
    sort_int_tab(tab);
}
int t_stack_check(t_stack *stack_a, int *tab)
{
    int i;
    t_node *temp;
    i = 0;
    temp = stack_a->top;
    while (temp)
    {
        if (tab[i++] != temp->data)
            return (write(1,"KO\n",3),0);
        temp = temp->next;
    }
    return (write(1,"OK\n",3),1);
}

int main(int argc, char **argv)
{
    char *line;
    t_stack stack_a;
    t_stack stack_b;
    t_node *temp;
    int *tab;
    stack_a.top = NULL;
    stack_a.bottom = NULL;
    stack_a.size = 0;
    stack_b.top = NULL;
    stack_b.bottom = NULL;
    stack_b.size = 0;
    if (!parsing(argc,argv,&stack_a) || argc == 1)
        return (write(1,"Error\n",6),0);
    tab = (int *)malloc(sizeof(int)*stack_a.size);
    init_sort_array(&stack_a,tab);
    while (1)
    {
        line = get_next_line(0);
        if (!line)
            break;
        if (!apply_operation(line,&stack_a,&stack_b))
            return (0);
    }
    return (t_stack_check(&stack_a,tab));
}

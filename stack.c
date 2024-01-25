#include "header.h"

void push(stack *stack,int data)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->data = data;
    if(stack->top)
    {
        new_node->next = stack->top;
        stack->top = new_node;
    }
    else
    {
        stack->top = new_node;
        stack->bottom = new_node;
    }
    stack->size++;
}
node *pop(stack *stack)
{
    node *popped;
    if(!stack->top)
    {
        puts("the stack is empty");
        return NULL;
    }
    popped = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    return popped;
}
int is_empty(stack *stack)
{
    return(stack->size <= 0);
}
void pa(stack *stack_a,stack *stack_b)
{
    if(is_empty(stack_b) != 1)
    {
        push(stack_a, stack_b->top->data);
        free(pop(stack_b));
    }
}
void Pb(stack *stack_a,stack *stack_b)
{
    if(is_empty(stack_a) != 1)
    {
        push(stack_b,stack_a->top->data);
        free(pop(stack_a));
    }
}
void Sa(stack *stack_a)
{
    node *temp = stack_a->top->next;
    stack_a->top->next = stack_a->top->next->next;
    temp->next = stack_a->top;
    stack_a->top = temp;
}
void Sb(stack *stack_b)
{
    Sa(stack_b);
}
void ra(stack *stack_a)
{
    node *temp;
    temp = stack_a->top;
    stack_a->top = stack_a->top->next;
    stack_a->bottom->next = temp;
    temp->next = NULL;
    stack_a->bottom = temp;
}
void rb(stack *stack_b)
{
    ra(stack_b);
}
void rr(stack *stack_a,stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
void rrr(stack *stack_a,stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
void rra(stack *stack_a)
{
    node *temp;
    node *befor_last_element;
    temp = stack_a->top;
    while(temp->next)
    {
        befor_last_element = temp;
        temp = temp->next;
    }
    befor_last_element->next = NULL;
    stack_a->bottom->next = stack_a->top;
    stack_a->top = stack_a->bottom;
    stack_a->bottom = befor_last_element;
}
void rrb(stack *stack_b)

#define RED "\033[31m"
#define RESET "\033[0m"
{
    rra(stack_b);
}

void sig_handler(int signo)
{
    (void)signo;
}

int main(int argc,char **argv)
{
    if(argc > 1)
    {
        stack *stack_a = (stack *)malloc(sizeof(stack));
        stack *stack_b = (stack *)malloc(sizeof(stack));
        stack_a->top = NULL;
        stack_b->top = NULL;
        stack_a->size = 0;
        stack_b->size = 0;
        longest_increasing_subsequence_caller(stack_a,stack_b,argc,argv);
        // puts(" stack_a   ");
        //     for(int i = 500; i >= 0; i--) {
        //         printf("%d ", i);
        //     }
        // while(stack_a->top)
        // {   
        //     int data = stack_a->top->data;
        //     stack_a->top = stack_a->top->next;
        //     if (stack_a->top && data < stack_a->top->data)
        //         printf("%d\n",data);
        //     else
        //     {
        //         s++;
        //         printf(RED"%d\n"RESET, data);
        //     }
        // }
        // puts("\n stack_b  ");
        // while(stack_b->top)
        // {   
        //     printf("\n|   %d   |\n",stack_b->top->data);
        //     stack_b->top = stack_b->top->next;
        // }
        free(stack_a);
        free(stack_b);
    }
}
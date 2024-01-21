#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct stack{
    int size;
    node *top;
}stack;
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
        stack->top = new_node;
    stack->size++;
}
node *pop(stack *stack)
{
    if(!stack->top)
    {
        puts("the stack is empty");
        return NULL;
    }
    node *popped;
    popped = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    return popped;
}
int is_empty(stack *stack)
{
    return(stack->size <= 0);
}
void push_a(stack *stack_a,stack *stack_b)
{
    if(is_empty(stack_b) != 1)
    {
        push(stack_a,stack_b->top->data);
        free(pop(stack_b));
    }
}
void push_b(stack *stack_a,stack *stack_b)
{
    if(is_empty(stack_a) != 1)
    {
        push(stack_b,stack_a->top->data);
        free(pop(stack_a));
    }
}
void swap_a(stack *stack_a)
{
    node *temp = stack_a->top->next;
    stack_a->top->next = stack_a->top->next->next;
    temp->next = stack_a->top;
    stack_a->top = temp;
}
void swap_b(stack *stack_b)
{
    swap_a(stack_b);
}
void rotate_a(stack *stack_a)
{
    node *temp;
    node *befor_last;
    temp = stack_a->top;
    while(stack_a->top->next)
        stack_a->top = stack_a->top->next;
    stack_a->top->next = temp;
    stack_a->top = temp->next;
    temp->next = NULL;
}
void rotate_b(stack *stack_b)
{
    void rotate_a(stack_b);
}
void reverse_rotate_a(stack *stack_a)
{
    while(stack_a->top->next)
        stack_a->top = stack_a->top->next
}
int main()
{
    stack *stack_a = (stack *)malloc(sizeof(stack));
    stack *stack_b = (stack *)malloc(sizeof(stack));
    stack_a->top = NULL;
    stack_b->top = NULL;
    stack_a->size = 0;
    stack_b->size = 0;
    push(stack_a,1);
    push(stack_a,2);
    push(stack_a,3);
    push(stack_a,4);
    push(stack_a,5);
    rotate_a(stack_a);
    printf("%d\n",stack_a->top->data);
}
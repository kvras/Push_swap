#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

typedef struct node{
    int data;
    struct node *next;
}   node;

typedef struct stack{
    int size;
    node *top;
    node *bottom;
}   stack;

typedef struct best_move{
    int position_b;
    int position_a;
    int size_a;
    int size_b;
    int metric;
    int cost;
}   best_move;

void print_stack(stack *stack);


int LIS(int* nums, int numsSize, int* maxSeq);
void push(stack *stack,int data);
node *pop(stack *stack);
int is_empty(stack *stack);
void pa(stack *stack_a,stack *stack_b);
void Pb(stack *stack_a,stack *stack_b);
void Sa(stack *stack);
void Sb(stack *stack);
void ra(stack *stack);
void rb(stack *stack);
void rra(stack *stack_a);
void rrb(stack *stack_b);
void rr(stack *stack_a,stack *stack_b);
void rrr(stack *stack_a,stack *stack_b);
int search(int *array,int size,int number);
void lis_filter(stack *stack_a,stack *stack_b,int *sequence,int len);
void longest_increasing_subsequence_caller(stack *stack_a,stack *stack_b,int argc,char **argv);
void push_back(stack *stack_a,stack *stack_b);
int set(int r,int rr,int rrr,int cost);
void calculator(stack *stack_a,stack *stack_b,int count_a,int count_b,best_move *best_move);
void execute(stack *stack_a,stack *stack_b,best_move *best_move);
int min(int a,int b);
int max(int a,int b);
void r_handler_a(stack *stack_a,int position_a,int size_a);
void r_handler_b(stack *stack_b,int position_b,int size_b);
void rr_handler(stack *stack_a,stack *stack_b,best_move *best_move);
void rrr_handler(stack *stack_a,stack *stack_b,best_move *best_move);
#endif
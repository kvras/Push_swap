#include "header.h"

//int *parsing(int argc,char **argv)
// {
//     int i;
//     int *instence; 
//     instence = (int *)malloc((argc-1)*4);
//     i = 1;
//     while(i < argc)
//     {
//         ft_split(argv[i],instence,argc-(i++));
//     }
//     return sequence;
// }
int search(int *array,int size,int number)
{
    int i = 0;
    while(i < size)
    {
        if(array[i] == number)
            return 1;
        i++;
    }
    return 0;
}
void lis_filter(stack *stack_a,stack *stack_b,int *sequence,int len)
{
    int count = 0;
    int size = stack_a->size;
     while(count < size)
        {
            if(search(sequence,len,count))
            {
                ra(stack_a);
                printf("ra\n");
                count++;
                continue;
            }
            Pb(stack_a,stack_b);
            printf("pb\n");
            count++;
        }
}
void longest_increasing_subsequence_caller(stack *stack_a,stack *stack_b,int argc,char **argv)
{
        int i;
        int len;
        int *sequence; 
        int *instence; 
        int size_1 = stack_a->size;
        instence = (int *)malloc((argc-1)*4);
        sequence = (int *)malloc((argc-1)*4);
        i = 1;
        while(i < argc)
        {
            instence[i-1]=atoi(argv[i]);
            push(stack_a,atoi(argv[argc-(i++)]));
        }
        len = LIS(instence,stack_a->size,sequence);
        //printf("the length of the longest increasing subsequence is %d\n",len);
        lis_filter(stack_a,stack_b,sequence,len);
        push_back(stack_a,stack_b);
        free(sequence);
        free(instence);
}
int min(int a,int b)
{
    if(a < b)
        return a;
    return b;
}
int max(int a,int b)
{
    if(a > b)
        return a;
    return b;
}
void r_handler_a(stack *stack_a,int position_a,int size_a)
{
    int i = 0;
    if(position_a < (size_a - position_a))
    {
        while(position_a - i)
        {
            ra(stack_a);
            printf("ra\n");
            i++;
        }
        return ;
    }
    while(size_a - position_a - i)
    {
        rra(stack_a);
        printf("rra\n");
        i++;
    }
}
void r_handler_b(stack *stack_b,int position_b,int size_b)
{
    int i = 0;
    if(position_b < (size_b - position_b))
    {
        while(position_b - i)
        {
            ra(stack_b);
            printf("rb\n");
            i++;
        }
        return ;
    }
    while(size_b - position_b - i)
    {
        rra(stack_b);
        printf("rrb\n");
        i++;
    }
}
void rr_handler(stack *stack_a,stack *stack_b,best_move *best_move)
{
    int i = 0;
    while(i<min(best_move->position_a,best_move->position_b))
    {
        rr(stack_a,stack_b);
        printf("rr\n");
        i++;
    }
    i = 0;
    if(best_move->position_a < best_move->position_b)
    {
        while(best_move->position_b - best_move->position_a -(i++))
        {
            rb(stack_b);
            printf("rb\n");
        }
        pa(stack_a,stack_b);
        printf("pa\n");
        return;
    }
    while(best_move->position_a - best_move->position_b -(i++))
    {
        ra(stack_a);
        printf("ra\n");
    }
    pa(stack_a,stack_b);
    printf("pa\n");
}
void rrr_handler(stack *stack_a,stack *stack_b,best_move *best_move)
{
    int i = 0;
    while(i<min(best_move->size_a - best_move->position_a,best_move->size_b - best_move->position_b))
    {
        rrr(stack_a,stack_b);
        printf("rrr\n");
        i++;
    }
    i = 0;
    if(best_move->size_a - best_move->position_a < best_move->size_b - best_move->position_b)
    {
        while(best_move->size_b - best_move->position_b-best_move->size_a + best_move->position_a-(i++))
        {
            rrb(stack_b);
            printf("rrb\n");
        }
        pa(stack_a,stack_b);
        printf("pa\n");
        return;
    }
    while(best_move->size_a - best_move->position_a-best_move->size_b + best_move->position_b-(i++))
    {
        rra(stack_a);
        printf("rra\n");
    }
    pa(stack_a,stack_b);
    printf("pa\n");
}

void execute(stack *stack_a,stack *stack_b,best_move *best_move)
{
   if(best_move->metric == 1)
   {
        r_handler_a(stack_a,best_move->position_a,best_move->size_a);
        r_handler_b(stack_b,best_move->position_b,best_move->size_b);
        pa(stack_a,stack_b);
        printf("pa\n");
   }
    else if(best_move->metric == 2)
        rr_handler(stack_a,stack_b,best_move);
    else
        rrr_handler(stack_a,stack_b,best_move);
}
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
    int i = 0;
    node *temp = stack->top;
    while(temp)
    {
        printf("|%d| %d \n",i,temp->data);
        temp = temp->next;
        i++;
    }
    puts("-----");
}

void push_back(stack *stack_a,stack *stack_b)
{
    best_move *best_move;
    node *temp_top_b;
    node *temp_top_a;
    int min_value = INT_MAX;
    int count_b;
    int count_a;
    while(stack_b->size > 0)
    {
        best_move->cost = INT_MAX;
        temp_top_b = stack_b->top;
        count_b = 0;
        while(temp_top_b)
        {
            count_a = get_matching_index(stack_a, temp_top_b->data);
            calculator(stack_a,stack_b,count_a,count_b,best_move);
            count_b++;
            temp_top_b = temp_top_b->next;
        }
        execute(stack_a,stack_b,best_move);
    }
    temp_top_a = stack_a->top;
    while(temp_top_a)
    {
        if(temp_top_a->data < min_value)
            min_value = temp_top_a->data;
        temp_top_a = temp_top_a->next;
    }
    while(stack_a->top->data != min_value)
    {
        ra(stack_a);
        printf("ra\n");
    }
}
int set(int r,int rr,int rrr,int cost)
{
    if(r == cost)
        return 1;
    if(rr == cost)
        return 2;
    return 3;
}
void calculator(stack *stack_a,stack *stack_b,int count_a,int count_b,best_move *best_move)
{
    int cost;
    int metric;
    int r;
    int rr;
    int rrr;
    r = min((stack_b->size - count_b),count_b) + min((stack_a->size - count_a),count_a);
    //printf("r is %d\n",r);
    rr = max(count_b,count_a);
    //printf("rr is %d\n",rr);
    rrr = max(stack_b->size-count_b,stack_a->size-count_a);
   // printf("rrr is %d\n",rrr);
    cost = min(r,min(rr,rrr));
   // printf("cost is %d\n",cost);
    metric = set(r,rr,rrr,cost);
   // printf("the metric is %d\n",metric);
    if(cost < best_move->cost)
    {
        best_move->metric = metric;
        best_move->cost = cost;
        best_move->position_a = count_a;
        best_move->position_b = count_b;
        best_move->size_a = stack_a->size;
        best_move->size_b = stack_b->size;
    }
}


#include "includes/push_swap.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

static void set_up(t_list **stack, int argc, char **argv)
{
    init_list(stack, argc, argv);
    index_stack(stack);
    list_visualize(stack, 'A');
}

static void sort_stack(t_list **stack_a, t_list **stack_b)
{
    /*
    if (lst_size(**stack_a) <= 5)
        simple_sort(stack_a, stack_b);
    else
    */
    radix_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_list **stack_a;
    t_list **stack_b;

    if (argc < 2)
        return (-1);
    check_args(argc, argv);
    stack_a = (t_list **)malloc(sizeof(t_list));
    stack_b = (t_list **)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
    set_up(stack_a, argc, argv);
    if (is_sorted(stack_a))
    {
        free_stack(stack_a);
        free_stack(stack_b);
        return (0);
    }
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    //free_stack(stack_b);
    return (0);
}
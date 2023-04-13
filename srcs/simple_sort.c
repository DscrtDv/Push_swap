/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:12:35 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:12:38 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static int	get_min(t_list **stack)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min))
			min = head->index;
	}
	return (min);
}

int     sort_3(t_list **stack_a)
{
    int op;
    t_list *first;
    t_list *second;
    t_list *third;

    op = 0;
    first = *stack_a;
    second = first->next;
    third = second->next;
    if (first->index > second->index && second->index < third->index)
        op += sa(stack_a);
    else if (first->index > third->index && second->index < first->index)
        op += ra(stack_a);
    else if (first->index > third->index && second->index > first->index)
        op += rra(stack_a);
    else 
    {
        op += sa(stack_a);
        if (first->index == 1)
            op += rra(stack_a);
        else
            op += ra(stack_a);
    }
    return (op);
}

int    small_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int     op;
    int     next_min;
    t_list  *head;

    head = *stack_a;
    op = 0;
    next_min = 0;
    while (lst_size(stack_a) != 3)
    {
        while (head->index != next_min){
            op += ra(stack_a);
            head = *stack_a;
        }
        op += pb(stack_a, stack_b);
        next_min++;
    }
    op += sort_3(stack_a);
    while (lst_size(stack_b))
        op += pa(stack_b, stack_a);
    return op;
}

void    simple_sort(t_list **stack_a, t_list **stack_b, int *op)
{
    int size;

    if (is_sorted(stack_a) || !stack_a)
        return ;
    size = lst_size(stack_a);
    if (size == 2)
        *op = sa(stack_a);
    else if (size == 3)
        *op = sort_3(stack_a);
    else if (size > 3)
        *op = small_sort(stack_a, stack_b, size);
}

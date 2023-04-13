/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:12:28 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:12:31 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void    radix_sort(t_list **stack_a, t_list **stack_b, int *op)
{
    t_list  *head_a;
    int     i;
    int     j;
    int     max_num;
    int     max_shifts;

    i = 0;
    max_num = lst_size(stack_a) - 1;
    while ((max_num >> max_shifts) != 0)
        max_shifts++;
    while (i < max_shifts)
    {
        j = 0;
        while (j < (max_num + 1))
        {
            head_a = *stack_a;
            //if (i+1)bit is 1, leave in a (ra), else pb
            if ((head_a->index >> i) & 1)
                *op += ra(stack_a);
            else
                *op += pb(stack_a, stack_b);
            j++;
        }
        while (lst_size(stack_b))
            *op += pa(stack_b, stack_a);
        i++;
    }
}

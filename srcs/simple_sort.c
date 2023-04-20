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
		if ((head->index < min) && head->index != -1)
			min = head->index;
	}
	return (min);
}

static void	finish_sort_3(t_list **stack_a, int *op)
{
	*op += s_(stack_a, "sa\n");
	*op += r_(stack_a, "ra\n");
}

static void	sort_3(t_list **stack_a, int *op)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack_a;
	second = first->next;
	third = second->next;
	if ((first->index > second->index) && (second->index < third->index))
	{
		if (first->index > third->index)
			*op += r_(stack_a, "ra\n");
		else
			*op += s_(stack_a, "sa\n");
	}
	else if ((first->index > second->index) && (first->index > third->index))
	{
		*op += r_(stack_a, "ra\n");
		*op += s_(stack_a, "sa\n");
	}
	else if ((first->index > third->index) && (first->index < second->index))
		*op += rr_(stack_a, "rra\n");
	else
		finish_sort_3(stack_a, op);
}

static void	small_sort(t_list **stack_a, t_list **stack_b, int size, int *op)
{
	int		next_min;
	t_list	*head;

	head = *stack_a;
	next_min = 0;
	while (lst_size(stack_a) != 3)
	{
		while (head->index != next_min)
		{
			*op += r_(stack_a, "ra\n");
			head = *stack_a;
		}
		*op += p_(stack_a, stack_b, "pb\n");
		next_min++;
	}
	sort_3(stack_a, op);
	while (lst_size(stack_b))
		*op += p_(stack_b, stack_a, "pa\n");
}

void	simple_sort(t_list **stack_a, t_list **stack_b, int *op)
{
	int	size;

	if (is_sorted(stack_a) || !stack_a)
		return ;
	size = lst_size(stack_a);
	if (size == 2)
		*op = s_(stack_a, "sa\n");
	else if (size == 3)
		sort_3(stack_a, op);
	else if (size > 3)
		small_sort(stack_a, stack_b, size, op);
}

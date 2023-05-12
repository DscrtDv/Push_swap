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

static size_t	get_position(t_list **stack, int aim_index)
{
	t_list	*head;
	size_t	position;

	position = 0;
	head = *stack;
	while (head->index != aim_index)
	{
		head = head->next;
		position++;
	}
	return (position);
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

static void	small_sort(t_list **stack_a, t_list **stack_b, int *op)
{
	int		next_min;
	size_t	position;
	t_list	*head;

	head = *stack_a;
	next_min = 0;
	while (lst_size(stack_a) != 3)
	{
		position = get_position(stack_a, next_min);
		if (position == lst_size(stack_a) - 1)
			*op += rr_(stack_a, "rra\n");
		head = *stack_a;
		while (head->index != next_min)
		{
			r_(stack_a, "ra\n");
			head = *stack_a;
		}
		*op += p_(stack_a, stack_b, "pb\n");
		next_min++;
	}
	if (!is_sorted(stack_a))
		sort_3(stack_a, op);
	while (lst_size(stack_b))
		*op += p_(stack_b, stack_a, "pa\n");
}

/*
static void	small_sort(t_list **stack_a, t_list **stack_b, int *op)
{
	t_list	*head;
	int		initial_size;

	initial_size = lst_size(stack_a);
	head = *stack_a;
	while (lst_size(stack_a) != 3)
		*op += p_(stack_a, stack_b, "pb\n");
	if (!is_sorted(stack_a))
		sort_3(stack_a, op);
	while (lst_size(stack_b))
	{
		*op += p_(stack_b, stack_a, "pa\n");
		head = *stack_a;
		if (head->index == 1)
			*op += s_(stack_a, "sa\n");
		else if (head->index == 4 && initial_size == 5)
			*op += r_(stack_b, "ra\n");
		else if (head->index == 3 && initial_size == 4)
			*op += r_(stack_b, "ra\n");
	}
}
*/
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
		small_sort(stack_a, stack_b, op);
}

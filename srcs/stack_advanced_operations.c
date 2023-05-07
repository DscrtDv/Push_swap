/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_advanced_operations.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:12:44 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:12:50 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include <stddef.h>

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;
	t_list	*temp;

	if (!*stack || lst_size(stack) < 2)
		return (-1);
	else if (lst_size(stack) == 2)
		s_swap(stack);
	else
	{
		head = *stack;
		last = lst_getlast(stack);
		last->next = head;
		temp = head->next;
		head->next = NULL;
		*stack = temp;
	}
	return (0);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;
	t_list	*temp;
	size_t	len;

	len = lst_size(stack);
	if (!*stack)
		return ;
	else if (len == 2)
		s_swap(stack);
	else
	{
		head = *stack;
		last = lst_getlast(stack);
		last->next = head;
		*stack = last;
		temp = *stack;
		while (len-- != 1)
			temp = temp->next;
		if (temp->next)
			temp->next = NULL;
	}
}

int	s_push(t_list **from, t_list **to)
{
	t_list	*temp;
	t_list	*head_to;
	t_list	*head_from;

	if (!lst_size(from))
		return (-1);
	head_to = *to;
	head_from = *from;
	temp = head_from;
	head_from = head_from->next;
	*from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*to = head_to;
	}
	else
	{
		temp->next = head_to;
		*to = temp;
	}
	return (0);
}

int	s_pop(t_list **stack)
{
	int		stack_val;
	t_list	*ptr;
	t_list	*head;

	head = *stack;
	if (!head)
		return (-1);
	else
	{
		ptr = head;
		stack_val = head->content;
		head = head->next;
		*stack = head;
		free(ptr);
		return (stack_val);
	}
	return (-1);
}

int	s_swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		temp_val;
	int		temp_index;

	if (lst_size(stack) <= 1)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head || !next)
		error_log();
	temp_val = head->content;
	temp_index = head->index;
	head->content = next->content;
	head->index = next->index;
	next->content = temp_val;
	next->index = temp_index;
	return (0);
}

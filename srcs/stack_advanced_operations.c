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
	t_list	*HEAD;
	t_list	*last;
	t_list	*temp;

	if (!*stack || lst_size(stack) < 2)
		return (-1);
	else if (lst_size(stack) == 2)
		s_swap(stack);
	else
	{
		HEAD = *stack;
		last = lst_getlast(stack);
		last->next = HEAD;
		temp = HEAD->next;
		HEAD->next = NULL;
		*stack = temp;
	}
	return (0);
}

void	reverse_rotate(t_list **stack)
{
	t_list *HEAD;
	t_list *last;
	t_list *temp;
	size_t	len;

	len = lst_size(stack);
	if (!*stack)
		return ;
	else if (len == 2)
		s_swap(stack);
	else
	{
		HEAD = *stack;
		last = lst_getlast(stack);
		last->next = HEAD;
		*stack = last;
		temp = *stack;
		while (len-- != 1)
			temp = temp->next;
		if (temp->next)
			temp->next = NULL;
	}
}

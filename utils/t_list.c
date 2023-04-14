/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_list.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:13:23 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:13:28 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_list	*lst_new(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

size_t	lst_size(t_list **stack)
{
	size_t	len;
	t_list	*current;

	len = 0;
	current = *stack;
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}

t_list	*lst_getlast(t_list **stack)
{
	t_list	*current;
	size_t	len;

	len = lst_size(stack);
	if (!*stack)
		return (NULL);
	else if (len <= 1)
		return (*stack);
	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

void	lst_addfront(t_list **stack, t_list *node)
{
	if (!node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	node->next = *stack;
	*stack = node;
}

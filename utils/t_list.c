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
	while(current)
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

void	lst_addback(t_list **stack, t_list *node)
{
	t_list	*last;

	if (*stack)
	{
		last = lst_getlast(stack);
		last->next = node;
		node->next = NULL;
	}
}

int		s_push(t_list **from, t_list **to)
{
	t_list	*temp;
	t_list	*head_to;
	t_list	*head_from;

	if(!lst_size(from))
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

int		s_pop(t_list **stack)
{
	int		stack_val;
	t_list	*ptr;
	t_list *HEAD;

	HEAD = *stack;
	if (!HEAD)
		printf("Stack is empty, nothing to pop.\n");
	else
	{
		ptr = HEAD;
		stack_val = HEAD->content;
		HEAD = HEAD->next;
		*stack = HEAD;
		free(ptr);
		return (stack_val);
	}
	return (-1);
}

int	s_swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int 	temp_val;
	int		temp_index;

	if (lst_size(stack) <= 1)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head || !next)
		error_log("An error occured while swapping.");
	temp_val = head->content;
	temp_index = head->index;
	head->content = next->content;
	head->index = next->index;
	next->content = temp_val;
	next->index = temp_index;
	return (0);
}

void	list_visualize(t_list **stack_a, char c)
{
	t_list	*s_a;
	char *temp;

	s_a = *stack_a;
	ft_putstr_fd("___\n", 1);
	while (s_a)
	{
		temp = ft_itoa(s_a->content);
		//printf("|	%i	|index: %i | &: %p |next&: %p |\n", s_a->content,s_a->index, s_a, s_a->next);
		ft_putchar_fd('|', 1);
		ft_putstr_fd(temp, 1);
		ft_putstr_fd("|\n", 1);
		s_a = s_a->next;
	}
	ft_putstr_fd("---\n", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}


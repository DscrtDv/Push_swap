/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_index.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:13:15 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:13:18 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static t_list	*next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		current_min;

	min = NULL;
	head = *stack;
	current_min = 0;
	if (head)
	{
		while (head)
		{
			if (head->index == -1)
			{	
				if (!current_min || head->content < min->content)
				{
					min = head;
					current_min = 1;
				}
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = next_min(stack);
	while (head)
	{
		head->index = index++;
		head = next_min(stack);
	}
}

void	init_list(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**argt;

	argt = argv;
	while (argc-- > 1)
	{
		new = lst_new(ft_atoi(argt[argc]));
		lst_addfront(stack, new);
	}
}

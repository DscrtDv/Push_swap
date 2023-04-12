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
			if ((head->index == -1) && (!current_min || head->content < min->content))
			{
				min = head;
				current_min = 1;
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

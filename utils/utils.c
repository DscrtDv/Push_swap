#include "../includes/push_swap.h"

void	error_log(char *log)
{
	ft_putstr_fd(log, 1);
	ft_putstr_fd("exiting...\n", 1);
	exit(1);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list *head;
	t_list *temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}

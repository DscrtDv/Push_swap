/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:13:34 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:13:36 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
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
	t_list	*head;
	t_list	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(stack);
}

void	list_visualize(t_list **stack_a, char c)
{
	t_list	*s_a;
	char	*temp;

	s_a = *stack_a;
	ft_putstr_fd("___\n", 1);
	while (s_a)
	{
		temp = ft_itoa(s_a->content);
		ft_putchar_fd('|', 1);
		ft_putstr_fd(temp, 1);
		ft_putstr_fd("|\n", 1);
		s_a = s_a->next;
	}
	ft_putstr_fd("---\n", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

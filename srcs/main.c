/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:12:06 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:35:32 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
#include <stdarg.h>
#include <stddef.h>

static void	set_up(t_list **stack, int argc, char **argv)
{
	init_list(stack, argc, argv);
	index_stack(stack);
}

static void	print_stack(t_list **stack, char *str_op)
{
	list_visualize(stack, 'A');
	ft_putstr_fd("Stack sorted with ", 1);
	ft_putstr_fd(str_op, 1);
	ft_putstr_fd(" Operations\n", 1);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		op;
	char	*str_op;

	op = 0;
	if (lst_size(stack_a) <= 5)
		simple_sort(stack_a, stack_b, &op);
	else
		radix_sort(stack_a, stack_b, &op);
	if (!is_sorted(stack_a))
		error_log("An error occured while sorting the stack.\n");
	str_op = ft_itoa(op);
	//print_stack(stack_a, str_op);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	set_up(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		ft_putstr_fd("Stack is already sorted!\n", 1);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

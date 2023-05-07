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
		error_log();
	str_op = ft_itoa(op);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

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
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

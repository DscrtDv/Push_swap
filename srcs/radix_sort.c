/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:12:28 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:12:31 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static int	get_max_shift(int max_num)
{
	int	max_shifts;

	max_shifts = 0;
	while ((max_num >> max_shifts) != 0)
		max_shifts++;
	return (max_shifts);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int *op)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		max_num;
	int		max_shifts;

	i = 0;
	max_num = lst_size(stack_a) - 1;
	max_shifts = get_max_shift(max_num);
	while (i < max_shifts)
	{
		j = 0;
		while (j < (max_num + 1))
		{
			head_a = *stack_a;
			if ((head_a->index >> i) & 1)
				*op += r_(stack_a, "ra\n");
			else
				*op += p_(stack_a, stack_b, "pb\n");
			j++;
		}
		while (lst_size(stack_b))
			*op += p_(stack_b, stack_a, "pa\n");
		i++;
	}
}

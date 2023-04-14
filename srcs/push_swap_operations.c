/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_operations.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:12:19 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:12:22 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	s_(t_list **stack, char *name)
{
	if (!*stack)
		return (0);
	s_swap(stack);
	ft_putstr_fd(name, 1);
	return (1);
}

int	r_(t_list **stack, char *name)
{
	if (!*stack)
		return (0);
	rotate(stack);
	ft_putstr_fd(name, 1);
	return (1);
}

int	rr_(t_list **stack, char *name)
{
	if (!*stack)
		return (0);
	reverse_rotate(stack);
	ft_putstr_fd(name, 1);
	return (1);
}

int	p_(t_list **from, t_list **to, char *name)
{
	if (!*from || !to)
		return (0);
	s_push(from, to);
	ft_putstr_fd(name, 1);
	return (1);
}

#include "../includes/push_swap.h"

int	sa(t_list **stack_a)
{
	if (!*stack_a)
		return (0);
	s_swap(stack_a);
	return (1);
}

int	sb(t_list **stack_b)
{
	if (!*stack_b)
		return (0);
	s_swap(stack_b);
	return (1);
}

int ss(t_list **stack_a, t_list **stack_b)
{
	if (!(sa(stack_a)) || !(sb(stack_b)))
		return (0);
	return (1);
}

int	pa(t_list **from, t_list **to)
{
	if (!*from || !to)
		return (0);
	s_push(from, to);
	return (1);
}

int	pb(t_list **from, t_list **to)
{
	if (!*from || !to)
		return (0);
	s_push(from, to);
	return (1);
}

int	ra(t_list **stack_a)
{
	if (!*stack_a)
		return (0);
	rotate(stack_a);
	return (1);
}

int	rb(t_list **stack_b)
{
	if (!*stack_b)
		return (0);
	rotate(stack_b);
	return (1);
}

int rr(t_list **stack_a, t_list **stack_b)
{
	if (!(ra(stack_a)) || !(rb(stack_b)))
		return (0);
	return (1);
}

int	rra(t_list **stack_a)
{
	if (!*stack_a)
		return (0);
	reverse_rotate(stack_a);
	return (1);
}

int	rrb(t_list **stack_b)
{
	if (!*stack_b)
		return (0);
	reverse_rotate(stack_b);
	return (1);
}

int rrr(t_list **stack_a, t_list **stack_b)
{
	if (!(rra(stack_a)) || !(rrb(stack_b)))
		return (0);
	return (1);
}

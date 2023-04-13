#include "../includes/push_swap.h"

void	init_list(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char 	**argt;

	argt = argv;
	while (argc-- > 1)
	{
		new = lst_new(ft_atoi(argt[argc]));
		lst_addfront(stack, new);
	}
}
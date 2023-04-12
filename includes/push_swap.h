#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct s_list{
	int				content;
	int				index;
	struct s_list 	*next;
}					t_list;

//sorting
void	radix_sort(t_list **stack_a, t_list **stack_b);

//push-swap Operations
int sa(t_list **stack_a);
int sb(t_list **stack_b);
int ss(t_list **stack_a, t_list **stack_b);
int pa(t_list **from, t_list **to);
int pb(t_list **from, t_list **to);
int ra(t_list **stack_a);
int rb(t_list **stack_b);
int rr(t_list **stack_a, t_list **stack_b);
int rra(t_list **stack_a);
int rrb(t_list **stack_b);
int rrr(t_list **stack_a, t_list **stack_b);

//utils
void		error_log(char *log);
int			is_sorted(t_list **stack);
void		free_stack(t_list **stack);
//indexing
void		index_stack(t_list **stack);
//arg Checks
void		check_args(int argc, char **argv);
//t_list OPs
t_list		*lst_new(int value);
size_t		lst_size(t_list **stack);
t_list		*lst_getlast(t_list **stack);
void		lst_addfront(t_list **stack, t_list *node);
void		lst_addback(t_list **stack, t_list *node);
int			s_pop(t_list **stack);
int			s_swap(t_list **stack);
int			s_push(t_list **from, t_list **to);


//stack advanced Operations
int			rotate(t_list **stack);
void		reverse_rotate(t_list **stack);
//graphics
void		list_visualize(t_list **stack_a, char c);

//stack innit
void		init_list(t_list **stack, int argc, char **argv);

#endif

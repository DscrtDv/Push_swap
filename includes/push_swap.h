/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:11:11 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:11:17 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct s_list{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

//sorting
void		radix_sort(t_list **stack_a, t_list **stack_b, int *op);
void		simple_sort(t_list **stack_a, t_list **stack_b, int *op);

//push-swap Operations
int			s_(t_list **stack, char *name);
int			r_(t_list **stack, char *name);
int			rr_(t_list **stack, char *name);
int			p_(t_list **from, t_list **to, char *name);

//init and index
void		index_stack(t_list **stack);
void		init_list(t_list **stack, int argc, char **argv);

//arg Checks
void		check_args(int argc, char **argv);

//t_list OPs
t_list		*lst_new(int value);
size_t		lst_size(t_list **stack);
t_list		*lst_getlast(t_list **stack);
void		lst_addfront(t_list **stack, t_list *node);

//stack advanced Operations
int			rotate(t_list **stack);
void		reverse_rotate(t_list **stack);
int			s_pop(t_list **stack);
int			s_swap(t_list **stack);
int			s_push(t_list **from, t_list **to);

//utils
void		error_log(char *log);
int			is_sorted(t_list **stack);
void		free_stack(t_list **stack);
void		list_visualize(t_list **stack_a, char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:19:45 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/30 09:54:52 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

typedef struct s_stack
{
	int	*array;
	int	len;
	int	top;
}	t_stack;

typedef struct s_info
{
	int	max;
	int	min;
	int	s_lis;
	int	e_lis;
	int	ave;
}	t_info;

//parsing
int			parsing(char **tab);
int			i_parsing(long int *tab, int len);
int			int_lim(long int *tab, int len);

//remplissage ou outil pour tab
long int	*fill_i_tab(char **c_tab);
char		**fill_c_tab(char **tab);
int			len_tab(char **tab);
void		free_str(char **str);

//outil stack
int			where_is_min(t_stack *stack);
int			where_is_max(t_stack *stack);
void		print_stack(t_stack *stack);
int			where_is_ave(t_stack *stack, t_info info);
int			where_is_lis(t_stack *stack);


//operateur pour le deplacement de la stack
void		stack_push(t_stack *stack, int value);
void		stack_pop(t_stack *stack);
void		stack_swap(t_stack *stack);
void		stack_rotate(t_stack *stack);
void		stack_rev_rotate(t_stack *stack);
void		move_up(t_stack *a, t_stack *b, int n_b, int n_a);
void		move_d(t_stack *a, t_stack *b, int n_b, int n_a);
void		move(t_stack *a, t_stack *b, int n_b, int n_a);

//instruction
void		sa(t_stack *a_stack);
void		sb(t_stack *b_stack);
void		ss(t_stack *a_stack, t_stack *b_stack);
void		pa(t_stack *a_stack, t_stack *b_stack);
void		pb(t_stack *a_stack, t_stack *b_stack);
void		ra(t_stack *a_stack);
void		rb(t_stack *b_stack);
void		rr(t_stack *a_stack, t_stack *b_stack);
void		ra(t_stack *a_stack);
void		rrb(t_stack *b_stack);
void		rra(t_stack *a_stack);
void		rrr(t_stack *a_stack, t_stack *b_stack);

//verrif de la stack
int			stack_is_full(t_stack *stack);
int			stack_is_empty(t_stack *stack);
int			is_sort(t_stack *stack);

//push_swap
void		init_swap(long int *tab, int len);
void		push_swap(t_stack *a_stack, t_stack *b_stack, t_info *info);
int			n_pos(t_stack *a, int n);
int			n_cost(t_stack *a, t_stack *b, int n);
void		sort_3(t_stack *a);
void		sort_5(t_stack *a, t_stack *b);

//init arg
void		init_swap(long int *tab, int len);
t_info		init_info(t_stack *stack);
t_stack		init_stack(long int *tab, int len);

#endif
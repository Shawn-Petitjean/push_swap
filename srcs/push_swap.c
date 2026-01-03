/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2026/01/03 10:38:31 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


void	sort_lis(t_stack *a, t_stack *b, t_info *info)
{
	int	count;
	int	len;

	if (info->s_lis > a->top)
		info->s_lis--;
	count = info->s_lis - info->e_lis;
	// printf("s_lis = %d\ne_lis = %d\n", info->s_lis, info->e_lis);
	len = a->top - count;
	while (info->s_lis < a->top)
	{
		pb(a, b);
		len--;
	}
	while (count-- >= 0)
		ra(a);
	count = info->s_lis - info->e_lis;
	while (len > 0)
	{
		pb(a, b);
		len--;
	}
}

void	swap_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	y;
	int	temp;

	while (b->top >= 0)
	{
		i = 0;
		y = 0;
		while (i < b->top)
		{
			temp = n_cost(a, b, i);
			i++;
			if (temp > n_cost(a, b, i))
				y = i;
		}
	if (check_d(a, b, y, n_pos(a, b->array[y])))
		move_d(a, b, y, n_pos(a, b->array[y]));
	else if (check_d(a, b, y, n_pos(a, b->array[y])))
		move_up(a, b, y, n_pos(a, b->array[y]));
	else 
		move(a, b, y, n_pos(a, b->array[y]));
	}
}

int	check_u(t_stack *a, t_stack *b, int	i_b, int i_a)
{
	int	cost_up_a;
	int	cost_up_b;
	int	cost_d_a;
	int	cost_d_b;
	int	cost_d_t;
	int	cost_u_t;

	cost_up_a = a->top - i_a;
	cost_d_a = a->top - cost_up_a;
	cost_up_b = b->top - i_b;
	cost_d_b = b->top - cost_up_b;
	if (i_b < b->top /2 && i_a < a->top /2)
		return (0);
	if (cost_up_a < cost_up_b)
		cost_u_t = cost_up_b - cost_up_a;
	else
		cost_u_t = cost_up_a - cost_up_b;
	if (cost_d_a < cost_d_b)
		cost_d_t = cost_d_b - cost_d_a;
	else
		cost_d_t = cost_d_a - cost_d_b;
	if (i_b >= b->top /2 && i_a < a->top)
		if (cost_up_b + cost_d_a > cost_u_t)
			return (0);
	if (i_a >= a->top /2 && i_b < b->top)
		if (cost_up_a + cost_d_b > cost_u_t)
			return (0);
	else
		return (1);
}

int	check_d(t_stack *a, t_stack *b, int	i_b, int i_a)
{
	int	cost_up_a;
	int	cost_up_b;
	int	cost_d_a;
	int	cost_d_b;
	int	cost_d_t;
	int	cost_u_t;

	cost_up_a = a->top - i_a;
	cost_d_a = a->top - cost_up_a;
	cost_up_b = b->top - i_b;
	cost_d_b = b->top - cost_up_b;
	if (i_b >= b->top /2 && i_a >= a->top /2)
		return (0);
	if (cost_up_a < cost_up_b)
		cost_u_t = cost_up_b - cost_up_a;
	else
		cost_u_t = cost_up_a - cost_up_b;
	if (cost_d_a < cost_d_b)
		cost_d_t = cost_d_b - cost_d_a;
	else
		cost_d_t = cost_d_a - cost_d_b;
	if (i_b >= b->top /2 && i_a < a->top)
		if (cost_up_b + cost_d_a > cost_d_t)
			return (0);
	if (i_a >= a->top /2 && i_b < b->top)
		if (cost_up_a + cost_d_b > cost_d_t)
			return (0);
	else
		return (1);
}

void	last_sort(t_stack *a)
{
	int	min;

	min = where_is_min(a);
	if (min >= a->top/2)
	{
		while (min++ < a->top)
			ra(a);
	}
	else
		while (min >= 0)
			rra(a);
}

void	push_swap(t_stack *a, t_stack *b, t_info *info)
{
	sort_lis(a, b, info);
	// print_stack(a);
	// ft_printf("\n");
	// print_stack(b);
	// printf("\ncout pour mettre index de b dans a: %d", n_cost(a, b, b->top -1));
	swap_sort(a, b);
	last_sort(a);
	return ;
}
//654 231 5 0 14 800 11 215 1587 3854 2314 4 3 6 7 2 1 
//4 3 6 7 2 1 
// 15 12 7 13 14 3 4 1 2 5 9 10 11 8 6 
	// print_stack(a);
	// ft_printf("\n");
	// print_stack(b);
	// ft_printf("%d\n", n_pos(a, b->array[b->top]));
	// print_stack(a);
	// ft_printf("\n");
	// print_stack(b);
	// ft_printf("\n%d", n_pos(a, b->array[b->top -2]));
	// 5 13 8 4 9 3 12 10 11 2 15 14 7 6 1 
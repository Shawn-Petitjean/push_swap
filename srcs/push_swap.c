/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2026/01/04 09:06:40 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check(t_stack *a, t_stack *b, int	cost_d_b, int cost_d_a)
{
	int cost_d_t;
	int	cost_u_t;
	int	u_a_d_b;
	int	d_a_u_b;

	if (cost_d_b < cost_d_a)
		cost_d_t = cost_d_a;
	else
		cost_d_t = cost_d_b;
	u_a_d_b = cost_d_b;
	d_a_u_b = cost_d_a;
	cost_d_a = a->top - cost_d_a;
	cost_d_b = b->top - cost_d_b;
	if (cost_d_b < cost_d_a)
		cost_u_t = cost_d_a;
	else
		cost_u_t = cost_d_b;
	u_a_d_b += cost_d_a;
	d_a_u_b += cost_d_b;
	if ((u_a_d_b < cost_d_t && u_a_d_b < cost_u_t) 
	|| (d_a_u_b < cost_d_t && d_a_u_b < cost_u_t))
		return (0);
	if (cost_d_t <= cost_u_t)
		return (-1);
	return (1);
}

void	sort_lis(t_stack *a, t_stack *b, t_info *info)
{
	int	count;
	int	len;

	if (info->s_lis > a->top)
		info->s_lis--;
	count = info->s_lis - info->e_lis;
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
	int	less_c;
	int	temp;

	while (b->top >= 0)
	{
		i = 0;
		y = 0;
		less_c = n_cost(a, b, i, n_pos(a, b->array[i]));
		while (i < b->top)
		{
			i++;
			temp = n_cost(a, b, i, n_pos(a, b->array[i]));
			if (less_c >= temp)
			{
				y = i;
				less_c = temp;
			}
		}
		if (check(a, b, y, n_pos(a, b->array[y])) == -1)
			move_d(a, b, y, n_pos(a, b->array[y]));
		else if (check(a, b, y, n_pos(a, b->array[y])) == 1)
			move_up(a, b, y, n_pos(a, b->array[y]));
		else 
			move(a, b, y, n_pos(a, b->array[y]));
	}
}

void	last_sort(t_stack *a)
{
	int	min;

	min = where_is_min(a);
	if (min >= a->top /2)
	{
		while (min++ < a->top)
			ra(a);
		return ;
	}
	else
		while (min-- >= 0)
			rra(a);
	return ;
}

void	push_swap(t_stack *a, t_stack *b, t_info *info)
{
	sort_lis(a, b, info);
	swap_sort(a, b);
	last_sort(a);
	return ;
}

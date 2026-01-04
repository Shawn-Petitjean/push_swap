/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:48:05 by shawn             #+#    #+#             */
/*   Updated: 2026/01/04 09:22:26 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move(t_stack *a, t_stack *b, int i_b, int pos)
{
	if (i_b < b->top / 2)
	{
		while (i_b-- != -1)
			rrb(b);
	}
	else
	{
		while (i_b++ < b->top)
			rb(b);
	}
	if (pos == 0)
		rra(a);
	else if (pos < a->top / 2)
	{
		while (pos-- >= 0)
			rra(a);
	}
	else
	{
		while (pos++ < a->top)
			ra(a);
	}
	return (pa(b, a));
}

void	move_up(t_stack *a, t_stack *b, int i_b, int pos)
{
	int	temp_a;
	int	temp_b;

	temp_a = a->array[pos];
	temp_b = b->array[i_b];
	while (b->array[b->top] != temp_b && a->array[a->top] != temp_a)
		rr(a, b);
	while (b->array[b->top] != temp_b)
		rb(b);
	while (a->array[a->top] != temp_a)
		ra(a);
	pa(b, a);
}

void	move_d(t_stack *a, t_stack *b, int i_b, int pos)
{
	int	temp_a;
	int	temp_b;

	temp_a = a->array[pos];
	temp_b = b->array[i_b];
	while (b->array[b->top] != temp_b && a->array[a->top] != temp_a)
		rrr(a, b);
	while (b->array[b->top] != temp_b)
		rrb(b);
	while (a->array[a->top] != temp_a)
		rra(a);
	pa(b, a);
}

int	n_cost(t_stack *a, t_stack *b, int cost_d_b, int cost_d_a)
{
	int	cost_d_t;
	int	cost_u_t;
	int	u_a_d_b;
	int	d_a_u_b;

	if (cost_d_b < cost_d_a)
		cost_d_t = cost_d_a ;
	else
		cost_d_t = cost_d_b ;
	u_a_d_b = cost_d_b ;
	d_a_u_b = cost_d_a ;
	cost_d_a = a->top - cost_d_a;
	cost_d_b = b->top - cost_d_b;
	if (cost_d_b < cost_d_a)
		cost_u_t = cost_d_a ;
	else
		cost_u_t = cost_d_b ;
	u_a_d_b += cost_d_a;
	d_a_u_b += cost_d_b;
	if ((u_a_d_b < cost_d_t && u_a_d_b < cost_u_t)
		|| (d_a_u_b < cost_d_t && d_a_u_b < cost_u_t))
		return (is_move(d_a_u_b, u_a_d_b));
	if (cost_d_t < cost_u_t)
		return (cost_d_t);
	return (cost_u_t);
}

int	n_pos(t_stack *a, int n)
{
	int	i;
	int	temp;
	int	y;

	i = 0;
	temp = a->array[where_is_max (a)] - n;
	y = -1;
	while (i != a->top +1)
	{
		if (temp >= a->array[i] - n && a->array[i] - n > 0)
		{
			temp = a->array[i] - n;
			y = i;
		}
		i++;
	}
	if (y == -1)
		return (where_is_min(a));
	return (y);
}

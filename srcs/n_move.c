/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:48:05 by shawn             #+#    #+#             */
/*   Updated: 2026/01/02 16:51:25 by shapetit         ###   ########.fr       */
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

	temp_a = a->top -pos;
	temp_b = b->top -i_b;
	if (temp_a < temp_b)
	{
		while (temp_a-- > 1 && temp_b--)
			rr(a, b);
		while (temp_b-- > 0)
			rb(b);
	}
	else
	{
		while (temp_b-- > 0 && temp_a--)
			rr(a, b);
		while (temp_a-- > 0)
			ra(a);
	}
	pa(b, a);
	return ;
}

void	move_d(t_stack *a, t_stack *b, int i_b, int pos)
{
	if (pos < i_b)
	{
		while (pos-- >= 0 && i_b--)
			rrr(a, b);
		while (i_b--)
			rrb(b);
	}
	else
	{
		while (i_b-- >= 0 && pos--)
			rrr(a, b);
		while (pos--)
			rra(a);
	}
	pa(b, a);
	return ;
}

int	n_cost(t_stack *a, t_stack *b, int n)
{
	int	a_pos;
	int	b_pos;

	a_pos = n_pos(a, b->array[n]);
	b_pos = n;
	if (a_pos < a->top / 2 && b_pos < b->top / 2)
	{
		if (a_pos < b_pos)
			return (b_pos +1);
		else
			return (a_pos +1);
	}
	else if (a_pos > a->top / 2 && b_pos > b->top / 2)
	{
		a_pos = a->top - a_pos;
		b_pos = b->top - b_pos;
		if (a_pos > b_pos)
			return (a_pos +1);
		else 
			return (b_pos +1);
	}
	if (a_pos >= a->top / 2 && a_pos > 0)
		a_pos = a->top - a_pos;
	else
		a_pos++;
	if (b_pos >= b->top / 2 && b_pos > 0)
		b_pos = b->top - b_pos;
	else
		b_pos++;
	return (a_pos + b_pos);
}
	// if (i_n < b->top / 2)
	// {
	// 	while (i_n-- != -1)
	// 		rrb(b);
	// }
	// else 
	// {
	// 	while (i_n++ != b->top)
	// 		rb(b);
	// }
	// if (pos == 0)
	// 	rra(a);
	// else if (pos < a->top / 2)
	// {
	// 	while (pos-- >= 0)
	// 		rra(a);
	// }
	// else
	// {
	// 	while (pos++ != a->top +1)
	// 		ra(a);
	// }
	// return (pa(b, a));

int	n_pos(t_stack *a, int n)
{
	int	i;
	int	temp;
	int	y;

	i = 0;
	temp = a->array[where_is_max(a)] -n;
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
		return(where_is_min(a));
	return (y);
}

// int	good_n(t_stack *a, t_stack *b)
// {
// 	int	pos;

// 	pos = n_pos(a, b->array[b->top]);
// 	if (pos < 2 || pos > a->top -2)
// 		return (b->top);
// 	pos = n_pos(a, b->array[b->top -1]);
// 	if (pos < 2 || pos > a->top -2)
// 		return (b->top -1);
// 	pos = n_pos(a, b->array[0]);
// 	if (pos < 2 || pos > a->top -2)
// 		return (0);
// 	return (n_pos(a, b->array[b->top]));
// }

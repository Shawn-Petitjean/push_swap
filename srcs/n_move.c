/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:48:05 by shawn             #+#    #+#             */
/*   Updated: 2025/12/31 12:03:23 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move(t_stack *a, t_stack *b, int i_n, int pos)
{
	if (i_n < b->top / 2)
	{
		while (i_n-- != -1)
			rrb(b);
	}
	else 
	{
		while (i_n++ != b->top)
			rb(b);
	}
	if (pos == a->top +1 || pos == 0)
		return (pa(b, a));
	if (pos < a->top / 2)
	{
		while (pos-- != 0)
			rra(a);
	}
	else 
	{
		while (pos++ != a->top +1)
			ra(a);
	}
	return (pa(b, a));
}

	// if (n_a < a->top / 2)
	// 	while (n_a--)
	// 		rra(a);
	// else
	// {
	// 	n_a = a->top - n_a;
	// 	while (n_a < 0)
	// 		ra(a);
	// }
	// if (n_b < b->top / 2)
	// 	while (n_b--)
	// 		rrb(b);
	// else
	// {
	// 	n_b = b->top - n_b;
	// 	while (n_b--)
	// 		rb(b);
	// }
	// pa(b, a);
	
void	move_up(t_stack *a, t_stack *b, int n_b, int n_a)
{
	ft_printf("move_up\n");
	int	temp;

	n_a = a->top - n_a;
	n_b = b->top - n_b;
	temp = n_a + n_b;
	if (n_a < n_b)
	{
		while (temp-- > n_b)
			rr(a, b);
		n_b = n_b - n_a;
		while (n_b--)
			rb(b);
	}
	else
	{
		while (temp-- > n_a)
			rr(a, b);
		n_a = n_a - n_b;
		while (n_a--)
			ra(a);
	}
	pa(b, a);
	return ;
}

void	move_d(t_stack *a, t_stack *b, int n_b, int n_a)
{
	ft_printf("move_d\n");
	int	temp;

	temp = n_a + n_b;
	if (n_a < n_b)
	{
		while (temp-- != n_b)
			rrr(a, b);
		n_b = n_b - n_a;		
		while (n_b--)
			rrb(b);
	}
	else
	{
		while (temp-- != n_a)
			rrr(a, b);
		n_a = n_a - n_b;
		while (n_a--)
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
			return (a_pos);
		else 
			return (b_pos);
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


int	n_pos(t_stack *a, int n)
{
	int	i;
	int	temp;
	int	y;

	i = 0;
	y = 0;
	temp = a->array[where_is_max(a)];
	while (i != a->top +1)
	{
		if (temp > a->array[i] - n && a->array[i] - n > 0)
		{
			temp = a->array[i] - n;
			y = i + 1;
		}
		i++;
	}
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

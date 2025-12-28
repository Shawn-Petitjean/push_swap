/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:48:05 by shawn             #+#    #+#             */
/*   Updated: 2025/12/27 12:35:15 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move(t_stack *a, t_stack *b, int pos)
{
	int	temp_pos;

	temp_pos = pos;
	if (pos <= a->top /2)
	{
		while (temp_pos--)
			rra(a);
	}
	else
	{
		temp_pos = a->top - temp_pos; 
		while (temp_pos--)
			ra(a);
	}
	pb(a, b);
}

void	pre_move(t_stack *a, t_stack *b, int pos, int where_n)
{
	int	i;

	i = a->top;
	if (where_n == 0)
		rrb(b);
	else if (where_n == -1)
		sb(b);
	if (pos < a->top /2)
	{
		pa(a, b);
		while (i != pos++)
			rra(a);
	}
	else
	{
		while (pos != a->top)
		{
			pos++;
			ra(a);
		}
		pa(a, b);
	}
	return ;
}

int	n_pos(t_stack *a, int n)
{
	int	i;

	i = a->top;
	while (n > a->array[i] && i > 0)
		i--;
	return (i);
}

int	good_n(t_stack *a, t_stack *b)
{
	int	pos;

	pos = n_pos(a, b->array[b->top]);
	if (pos == a->top || (pos < 2 || pos > a->top -2))
		return (-2);
	pos = n_pos(a, b->array[b->top -1]);
	if (pos == a->top || (pos < 2 || pos > a->top -2))
		return (-1);
	pos = n_pos(a, b->array[0]);	
	if (pos == a->top || (pos < 2 || pos > a->top -2))
		return (0);
	return (n_pos(a, b->array[b->top]));
}

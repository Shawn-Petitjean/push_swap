/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/31 12:20:27 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_lis(t_stack *a, t_stack *b, t_info *info)
{
	int	count;

	count = info->s_lis - info->e_lis;
	while (info->s_lis < a->top)
		pb(a, b);
	while (count >= 0)
	{
		ra(a);
		count--;
	}
	count = info->s_lis - info->e_lis;
	count = a->top - count;
	while (count > 0)
	{
		pb(a, b);
		count--;
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
			if (temp < n_cost(a, b, i))
			{
				temp = n_cost(a, b, i);
				y = i;
			}
		}
		if (y < b->top / 2 && n_pos(a, b->array[y]) < a->top / 2)
			move_d(a, b, y, n_pos(a, b->array[y]));
		else if (y > b->top / 2 && n_pos(a, b->array[y]) > a->top / 2)
			move_up(a, b, y, n_pos(a, b->array[y]));
		else 
			move(a, b, y, n_pos(a, b->array[y]));
	}
}

void	push_swap(t_stack *a, t_stack *b, t_info *info)
{
	sort_lis(a, b, info);
	swap_sort(a, b);
	// print_stack(a);
	// ft_printf("\n");
	// print_stack(b);
	// ft_printf("|||||\n");
	// move(a, b, 0, n_pos(a, b->array[0]));
	// move_d(a, b, b->array[0], n_pos(a, b->array[0]));
	// print_stack(a);
	// ft_printf("\n");
	// print_stack(b);
	// move(a, b, b->top, n_pos(a, b->array[b->top]));
	// print_stack(a);
	// ft_printf("\n");
	// print_stack(b);
	// move_d(a, b, 2, n)
	return ;
}
//654 231 5 0 14 800 11 215 1587 3854 2314
//4 3 6 7 5 2 1 
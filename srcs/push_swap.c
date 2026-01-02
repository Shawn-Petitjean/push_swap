/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:17:58 by shapetit          #+#    #+#             */
/*   Updated: 2026/01/02 16:29:42 by shapetit         ###   ########.fr       */
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
			{
				temp = n_cost(a, b, i);
				y = i;
			}
		}
	// if (y < b->top / 2 && n_pos(a, b->array[y]) < a->top / 2)
	// 	move_d(a, b, y, n_pos(a, b->array[y]));
	if (y >= b->top / 2 && n_pos(a, b->array[y]) >= a->top / 2)
		move_up(a, b, y, n_pos(a, b->array[y]));
	else 
		move(a, b, y, n_pos(a, b->array[y]));
	}
}

void	push_swap(t_stack *a, t_stack *b, t_info *info)
{
	
	// print_stack(a);
	// ft_printf("\n");
	// print_stack(b);
	// printf("\n%d\n%d", info->s_lis, info->e_lis);
	sort_lis(a, b, info);
	// move_up(a, b, b->top -1, n_pos(a, b->array[b->top -1]));
	swap_sort(a, b);

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_verrif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:44:30 by shapetit          #+#    #+#             */
/*   Updated: 2026/01/04 09:24:35 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	stack_is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int	stack_is_full(t_stack *stack)
{
	return ((stack->len - 1) == stack->top);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
		ft_printf("%d\n", stack->array[i--]);
}

int	where_is_ave(t_stack *stack, t_info info)
{
	int	i;
	int	y;

	i = 0;
	y = stack->top;
	while (stack->array[i] <= info.ave)
		i++;
	while (stack->array[y] <= info.ave)
		y--;
	if ((stack->top - y) <= i)
		return (y);
	else
		return (i);
}

int	is_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->array[i] < stack->array[i +1])
		{
			while (stack->array[i] < stack->array[i +1])
			{
				i++;
				if (i == stack->top)
					return (2);
			}
			return (0);
		}
		while (stack->array[i] > stack->array[i +1])
		{
			i++;
			if (i == stack->top)
				return (1);
		}
		return (0);
	}
	return (0);
}

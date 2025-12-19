/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_verrif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:44:30 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/17 14:20:59 by shapetit         ###   ########.fr       */
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

int	is_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top +1)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:03:56 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/22 13:38:58 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stack_push(t_stack *stack, int value)
{
	if (stack_is_full(stack))
		return ;
	stack->array[++stack->top] = value;
	return ;
}

void	stack_pop(t_stack *stack)
{
	if (stack_is_empty(stack))
		return ;
	stack->top--;
	return ;
}

void	stack_swap(t_stack *stack)
{
	int	temp;

	if (stack->top < 1)
		return ;
	temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top -1];
	stack->array[stack->top -1] = temp;
	return ;
}

void	stack_rotate(t_stack *stack)
{
	int	*temp_array;
	int	i;
	int	y;

	y = 1;
	i = 0;
	temp_array = malloc(sizeof (int) * (stack->top + 1));
	while (i != stack->top)
	{
		temp_array[y] = stack->array[i];
		i++;
		y++;
	}
	temp_array[0] = stack->array[stack->top];
	i = 0;
	while (i != stack->top +1)
	{
		stack->array[i] = temp_array[i];
		i++;
	}
	return ;
}

void	stack_rev_rotate(t_stack *stack)
{
	int	*temp_array;
	int	i;
	int	y;

	y = 0;
	i = 1;
	temp_array = malloc(sizeof (int) * (stack->top + 1));
	while (i != stack->top +1)
	{
		temp_array[y] = stack->array[i];
		i++;
		y++;
	}
	temp_array[stack->top] = stack->array[0];
	i = 0;
	while (i != stack->top +1)
	{
		stack->array[i] = temp_array[i];
		i++;
	}
	return ;
}

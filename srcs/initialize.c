/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shapetit <shapetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:47:47 by shapetit          #+#    #+#             */
/*   Updated: 2025/12/23 13:23:04 by shapetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	init_swap(long int *tab, int len)
{
	t_stack	a;
	t_stack	b;
	t_info	info;

	a = init_stack(tab, len);
	b = init_stack(NULL, len);
	info = init_info(&a);
	push_swap(&a, &b, info);
	free(a.array);
	free(b.array);
	return ;
}

t_info	init_info(t_stack *stack)
{
	t_info	info;
	int		ave;
	int		i;

	i = 0;
	ave = 0;
	malloc(stack->len * sizeof(int));
	info.max = stack->array[i];
	info.min = stack->array[i];
	info.lis = malloc(sizeof(int) * stack->len);
	while (i < stack->len)
	{
		if (info.max < stack->array[i])
			info.max = stack->array[i];
		if (info.min > stack->array[i])
			info.min = stack->array[i];
		ave += stack->array[i++];
	}
	i = where_is_lis(stack);
	info.ave = ave / stack->len;
	ave = 0;
	while (stack->array[i] > stack->array[i -1])
	{
		info.lis[ave++] = stack->array[i--];
	}
	return (info);
}

t_stack	init_stack(long int *tab, int len)
{
	t_stack	stack;
	int		i;
	int		*i_tab;

	i = 0;
	i_tab = malloc(len * sizeof(int));
	while (i < len && tab)
	{
		i_tab[i] = tab[i];
		i++;
	}
	i = len -1;
	stack.array = malloc(len * sizeof(int));
	stack.len = len;
	stack.top = -1;
	while (i >= 0 && tab)
		stack_push(&stack, i_tab[i--]);
	return (free (i_tab), free (tab), stack);
}

int	where_is_min(t_stack *stack)
{
	int	i;
	int	temp;
	int	min;

	i = 0;
	min = 0;
	temp = stack->array[i];
	while (i <= stack->top)
	{
		if (temp > stack->array[i])
		{
			min = i;
			temp = stack->array[i];
		}
		i++;
	}
	return (min);
}

int	where_is_max(t_stack *stack)
{
	int	i;
	int	temp;
	int	max;

	i = 0;
	max = 0;
	temp = stack->array[i];
	while (i <= stack->top)
	{
		if (temp < stack->array[i])
		{
			max = i;
			temp = stack->array[i];
		}
		i++;
	}
	return (max);
}

//654 231 5 0 14 800 11 215 1587 3854 2314
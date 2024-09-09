/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:08:28 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/08 19:54:07 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_min(t_node **stack)
{
	t_node	*tmp;
	t_node	*min;

	tmp = *stack;
	min = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (min->nb > tmp->nb)
			min = tmp;
	}
	return (min);
}

void	set_index(t_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = (stack_size(&stack) + 1) / 2;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= median)
			stack->median = 0;
		else
			stack->median = 1;
		stack = stack->next;
		i++;
	}
}

void	set_low_cost(t_node *stack)
{
	t_node	*low_cost;
	int		max;

	max = 2147483647;
	while (stack)
	{
		stack->low_cost = 1;
		if (stack->cost < max)
		{
			max = stack->cost;
			low_cost = stack;
		}
		stack = stack->next;
	}
	low_cost->low_cost = 0;
}

t_node	*get_low_cost(t_node *stack)
{
	while (stack)
	{
		if (stack->low_cost == 0)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_cost(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(&stack_a) + 1;
	len_b = stack_size(&stack_b) + 1;
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (stack_a->median == 1)
			stack_a->cost = len_a - stack_a->index;
		if (stack_a->target->median == 0)
			stack_a->cost += stack_a->target->index;
		else
			stack_a->cost += len_b - stack_a->target->index;
		stack_a = stack_a->next;
	}
}

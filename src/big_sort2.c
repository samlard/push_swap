/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:12:18 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/08 20:04:10 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_rotate(t_node **stack)
{
	t_node	*min;

	min = ft_find_min(stack);
	while (*stack != min)
	{
		if (min->median == 0)
			ra(stack, 0);
		else
			rra(stack, 0);
	}
}

void	move_b_a(t_node **stack_a, t_node **stack_b)
{
	while (*stack_a != (*stack_b)->target)
	{
		if ((*stack_b)->target->median == 0)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	set_index(*stack_a);
	pa(stack_b, stack_a);
}

void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*target;
	t_node	*tmp;
	int		best_friend;

	while (stack_b)
	{
		tmp = stack_a;
		best_friend = 2147483647;
		while (tmp)
		{
			if (stack_b->nb < tmp->nb && tmp->nb < best_friend)
			{
				best_friend = tmp->nb;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (best_friend == 2147483647)
			stack_b->target = ft_find_min(&stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	set_up_stack_b(t_node **stack_a, t_node **stack_b)
{
	set_index(*stack_a);
	set_index(*stack_b);
	set_target_b(*stack_a, *stack_b);
}

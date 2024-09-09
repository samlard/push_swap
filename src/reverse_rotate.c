/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:05:27 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/08 18:06:11 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack, int i)
{
	t_node	*last;
	t_node	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	last = find_last(stack);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = tmp;
	tmp->previous = last;
	(*stack) = last;
	if (i == 0)
		ft_printf("rra\n");
}

void	rrb(t_node **stack, int i)
{
	t_node	*last;
	t_node	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	last = find_last(stack);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = tmp;
	tmp->previous = last;
	(*stack) = last;
	if (i == 0)
		ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	rra(stack_a, 1);
	rrb(stack_b, 1);
	ft_printf("rrr\n");
}

void	rev_rotate_both(t_node **stack_a, t_node **stack_b, t_node *low_cost)
{
	while (*stack_a != low_cost && (*stack_a)->target != *stack_b)
	{
		rrr(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_b);
}

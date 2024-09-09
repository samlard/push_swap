/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:15:26 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/08 18:06:04 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack, int i)
{
	t_node	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = find_last(stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last->next->next = NULL;
	last->next->previous = last;
	if (i == 0)
		ft_printf("ra\n");
}

void	rb(t_node **stack, int i)
{
	t_node	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = find_last(stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last->next->next = NULL;
	last->next->previous = last;
	if (i == 0)
		ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	ra(stack_a, 1);
	rb(stack_b, 1);
	ft_printf("rr\n");
}

void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *low_cost)
{
	while (*stack_a != low_cost && (*stack_a)->target != *stack_b)
	{
		rr(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:08:42 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/06 18:18:38 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack, int i)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->previous->previous = *stack;
	(*stack)->previous->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->previous = (*stack)->previous;
	(*stack)->next = (*stack)->previous;
	(*stack)->previous = NULL;
	if (i == 0)
		ft_printf("sa\n");
}

void	sb(t_node **stack, int i)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->previous->previous = *stack;
	(*stack)->previous->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->previous = (*stack)->previous;
	(*stack)->next = (*stack)->previous;
	(*stack)->previous = NULL;
	if (i == 0)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	sa(stack_a, 1);
	sb(stack_b, 1);
	ft_printf("ss\n");
}

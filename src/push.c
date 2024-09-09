/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:10:47 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/05 23:27:06 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_from, t_node **stack_to)
{
	t_node	*tmp;

	tmp = *stack_from;
	if (!(*stack_from))
		return ;
	if ((*stack_to))
		(*stack_to)->previous = tmp;
	if ((*stack_from)->next)
		tmp->next->previous = NULL;
	*stack_from = tmp->next;
	tmp->next = *stack_to;
	*stack_to = tmp;
	ft_printf("pa\n");
}

void	pb(t_node **stack_from, t_node **stack_to)
{
	t_node	*tmp;

	tmp = *stack_from;
	if (!(*stack_from))
		return ;
	if ((*stack_to))
		(*stack_to)->previous = tmp;
	if ((*stack_from)->next)
		tmp->next->previous = NULL;
	*stack_from = (*stack_from)->next;
	tmp->next = *stack_to;
	*stack_to = tmp;
	ft_printf("pb\n");
}

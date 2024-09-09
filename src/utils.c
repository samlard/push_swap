/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:20:42 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/05 21:27:32 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node **stack_a)
{
	t_node	*last;

	last = *stack_a;
	while (last->next)
		last = last->next;
	return (last);
}

int	stack_size(t_node **stack)
{
	t_node	*tmp;
	int		i;

	if (!*stack)
		return (0);
	i = 0;
	tmp = *stack;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	sorted_list(t_node **stack)
{
	int		n;
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		n = tmp->nb;
		tmp = tmp->next;
		if (n > tmp->nb)
			return (1);
	}
	return (0);
}

t_node	*ft_find_max(t_node **stack)
{
	t_node	*tmp;
	t_node	*max;

	tmp = *stack;
	max = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (max->nb < tmp->nb)
			max = tmp;
	}
	return (max);
}

void	ft_little_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*max;

	if (stack_size(stack_a) == 1)
	{
		sa(stack_a, 0);
		ft_quit(stack_a, stack_b, NULL);
	}
	max = ft_find_max(stack_a);
	if (*stack_a == max)
		ra(stack_a, 0);
	if ((*stack_a)->next == max)
		rra(stack_a, 0);
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		sa(stack_a, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:16:56 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/08 20:45:20 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_on_top(t_node **stack, t_node *low_cost, char c)
{
	while (*stack != low_cost)
	{
		if (c == 'a' && low_cost->median == 0)
			ra(stack, 0);
		if (c == 'a' && low_cost->median == 1)
			rra(stack, 0);
		if (c == 'b' && low_cost->median == 0)
			rb(stack, 0);
		if (c == 'b' && low_cost->median == 1)
			rrb(stack, 0);
	}
}

void	move_a_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*low_cost;

	low_cost = get_low_cost(*stack_a);
	if (low_cost->median == 0 && low_cost->target->median == 0)
		rotate_both(stack_a, stack_b, low_cost);
	else if (low_cost->median == 1 && low_cost->target->median == 1)
		rev_rotate_both(stack_a, stack_b, low_cost);
	node_on_top(stack_a, low_cost, 'a');
	node_on_top(stack_b, low_cost->target, 'b');
	pb(stack_a, stack_b);
}

void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*target;
	t_node	*tmp;
	int		best_friend;

	while (stack_a)
	{
		tmp = stack_b;
		best_friend = -2147483648;
		while (tmp)
		{
			if (stack_a->nb > tmp->nb && tmp->nb > best_friend)
			{
				best_friend = tmp->nb;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (best_friend == -2147483648)
			stack_a->target = ft_find_max(&stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	set_up_stack_a(t_node **stack_a, t_node **stack_b)
{
	set_index(*stack_a);
	set_index(*stack_b);
	set_target_a(*stack_a, *stack_b);
	set_cost(*stack_a, *stack_b);
	set_low_cost(*stack_a);
}

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = stack_size(stack_a);
	if (len_a-- > 2 && sorted_list(stack_a) == 1)
		pb(stack_a, stack_b);
	if (len_a > 2 && sorted_list(stack_a) == 1)
	{
		len_a--;
		pb(stack_a, stack_b);
	}
	while (len_a > 2 && sorted_list(stack_a) == 1)
	{
		set_up_stack_a(stack_a, stack_b);
		move_a_b(stack_a, stack_b);
		len_a--;
	}
	ft_little_sort(stack_a, stack_b);
	while (*stack_b)
	{
		set_up_stack_b(stack_a, stack_b);
		move_b_a(stack_a, stack_b);
	}
	set_index(*stack_a);
	last_rotate(stack_a);
}

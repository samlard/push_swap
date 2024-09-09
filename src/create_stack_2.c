/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:24:41 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/05 21:27:18 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double(long tmp, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (tmp == ft_atol(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_create_new(long nb, t_node **stack_a)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nb = nb;
	new_node->next = NULL;
	if (!(*stack_a))
	{
		*stack_a = new_node;
		(*stack_a)->previous = NULL;
		return ;
	}
	else
	{
		last_node = find_last(stack_a);
		new_node->previous = last_node;
		last_node->next = new_node;
	}
}

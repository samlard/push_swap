/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:08:44 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/08 20:46:26 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_node_nb(t_node *node)
{
	if (!node)
		return ;
	ft_printf("%i\n", node->nb);
}

void	ft_print_list(t_node *stack)
{
	t_node	*ptr;

	ptr = stack;
	while (ptr)
	{
		ft_print_node_nb(ptr);
		ptr = ptr->next;
	}
}

void	ft_print_stack(t_node *stack, char *name)
{
	ft_print_list(stack);
	ft_printf("%s\n----------\n", name);
}

void	ft_print_both_stacks(t_node *stack_a, t_node *stack_b)
{
	t_node	*ptr_a;
	t_node	*ptr_b;

	ft_printf("\nA B\n");
	ptr_a = stack_a;
	ptr_b = stack_b;
	while (ptr_a || ptr_b)
	{
		if (ptr_a)
		{
			ft_printf("%i ", ptr_a->nb);
			ptr_a = ptr_a->next;
		}
		else
			ft_printf("  ");
		if (ptr_b)
		{
			ft_printf("%i\n", ptr_b->nb);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf(" \n");
	}
	ft_printf("\n");
}

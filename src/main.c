/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:28:38 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/08 20:49:46 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		ft_quit(&stack_a, &stack_b, "");
	stack_a = malloc(sizeof(t_node));
	stack_b = malloc(sizeof(t_node));
	if (!stack_a || !stack_b)
		ft_quit(&stack_a, &stack_b, "Error");
	stack_a = NULL;
	stack_b = NULL;
	ft_create_stack(&stack_a, argv, &stack_b);
	if (sorted_list(&stack_a) == 1)
	{
		if (stack_size(&stack_a) < 3)
			ft_little_sort(&stack_a, &stack_b);
		else
			big_sort(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	system("leaks push_swap");
	return (0);
}

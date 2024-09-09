/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:02:08 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/09 17:53:18 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quit(t_node **stack_a, t_node **stack_b, char *str)
{
	if (*stack_a)
		ft_free_stack(stack_a);
	if (*stack_b)
		ft_free_stack(stack_b);
	if (str)
		ft_putendl_fd(str, 2);
	system("leaks push_swap");
	exit(1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	if (*stack)
	{
		while ((*stack)->next)
		{
			tmp = (*stack);
			*stack = (*stack)->next;
			free(tmp);
		}
		free(*stack);
		*stack = NULL;
	}
}

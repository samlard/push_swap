/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:21:32 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/09 17:56:12 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *str, int i)
{
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return (1);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	i;
	long	signe;
	long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * signe);
}

void	ft_check_args(char **s_argv, t_node **stack_a, t_node **stack_b)
{
	int		j;
	long	tmp;

	j = 0;
	while (s_argv[j])
	{
		tmp = ft_atol(s_argv[j]);
		if (is_digit(s_argv[j], 0) == 1)
		{
			ft_free_tab(s_argv);
			ft_quit(stack_a, stack_b, "Error");
		}
		if (ft_check_double(tmp, s_argv, j) == 1)
		{
			ft_free_tab(s_argv);
			ft_quit(stack_a, stack_b, "Error");
		}
		if (tmp > (long)2147483647 || tmp < (long)-2147483648)
		{
			ft_free_tab(s_argv);
			ft_quit(stack_a, stack_b, "Error");
		}
		ft_create_new(tmp, stack_a);
		j++;
	}
}

void	ft_prepare_argv(char *argv1, t_node **stack_a, t_node **stack_b)
{
	char	**str;
	int		i;

	str = ft_split(argv1, 32);
	i = 0;
	while (str[i])
		i++;
	if (i < 1)
		ft_quit(stack_a, stack_b, "Error");
	ft_check_args(str, stack_a, stack_b);
	ft_free_tab(str);
}

void	ft_create_stack(t_node **stack_a, char **argv, t_node **stack_b)
{
	int		i;
	char	*tmp;
	char	*str;
	char	*args;

	str = ft_strdup("");
	i = 1;
	while (argv[i])
	{	
		args = ft_strdup(argv[i]);
		tmp = ft_strjoin(args, " ");
		str = ft_strjoin(str, tmp);
		i++;
		free(tmp);
	}
	ft_prepare_argv(str, stack_a, stack_b);
	free(str);
}

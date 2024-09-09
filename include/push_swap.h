/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:29:27 by ssoumill          #+#    #+#             */
/*   Updated: 2024/09/09 17:52:26 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nb;
	int				index;
	int				median;
	int				cost;
	int				low_cost;
	struct s_node	*next;
	struct s_node	*previous;
	struct s_node	*target;
}					t_node;

void				ft_print_both_stacks(t_node *stack_a, t_node *stack_b);
void				ft_free_tab(char **tab);
// first part of algo function

void				big_sort(t_node **stack_a, t_node **stack_b);
void				set_up_stack_a(t_node **stack_a, t_node **stack_b);
void				set_target_a(t_node *stack_a, t_node *stack_b);
void				move_a_b(t_node **stack_a, t_node **stack_b);
void				node_on_top(t_node **stack, t_node *low_cost, char c);

// second part of algo function

void				rev_rotate_both(t_node **stack_a, t_node **stack_b,
						t_node *low_cost);
void				set_target_b(t_node *stack_a, t_node *stack_b);
void				move_b_a(t_node **stack_a, t_node **stack_b);
void				last_rotate(t_node **stack);
void				set_up_stack_b(t_node **stack_a, t_node **stack_b);

// Utils function

void				set_cost(t_node *stack_a, t_node *stack_b);
t_node				*get_low_cost(t_node *stack);
void				set_low_cost(t_node *stack);
t_node				*ft_find_min(t_node **stack);
t_node				*find_last(t_node **stack_a);
int					stack_size(t_node **stack);
int					sorted_list(t_node **stack);
t_node				*ft_find_max(t_node **stack);
void				ft_little_sort(t_node **stack_a, t_node **stack_b);
void				set_index(t_node *stack);

// Parthing function

int					ft_check_double(long tmp, char **s_argv, int i);
void				ft_create_stack(t_node **stack_a, char **argv,
						t_node **stack_b);
long				ft_atol(const char *str);
void				ft_prepare_argv(char *argv1, t_node **stack_a,
						t_node **stack_b);
void				ft_check_args(char **s_argv, t_node **stack_a,
						t_node **stack_b);
int					is_digit(char *str, int i);
void				ft_create_new(long nb, t_node **stack_a);

// Error function

void				ft_free_stack(t_node **stack);
void				ft_quit(t_node **stack_a, t_node **stack_b, char *str);

// Rotate function

void				ra(t_node **stack, int i);
void				rr(t_node **stack_a, t_node **stack_b);
void				rb(t_node **stack, int i);
void				rotate_both(t_node **stack_a, t_node **stack_b,
						t_node *low_cost);

// Reverse rotate function
void				rra(t_node **stack, int i);
void				rrb(t_node **stack, int i);
void				rrr(t_node **stack_a, t_node **stack_b);
void				rev_rotate_both(t_node **stack_a, t_node **stack_b,
						t_node *low_cost);

// Swap function

void				sa(t_node **stack, int i);
void				sb(t_node **stack, int i);
void				ss(t_node **stack_a, t_node **stack_b);

// Push fonction

void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);

#endif
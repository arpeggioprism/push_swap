/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:43:19 by jshin             #+#    #+#             */
/*   Updated: 2022/07/07 01:27:00 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include "../libft/libft.h"
# include "db_linked_list.h"

void	push_swap(t_stack *a, t_stack *b);
void	is_max_min_main(t_stack *list, t_node *new_node, int data);
void	is_max_min(t_stack *list, int data);
void	stack_init(t_stack *list);
void	stack_push_back(t_stack *list, int data);
double	stack_peek(t_stack *stack);
void	stack_pop(t_stack *stack);
void	stack_push(t_stack *stack, int data);
double	pa(t_stack *a, t_stack *b);
double	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sort_only_three(t_stack *a);
void	print_error(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:43:19 by jshin             #+#    #+#             */
/*   Updated: 2022/07/11 13:04:05 by jshin            ###   ########.fr       */
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

void	print_error(void);
void	push_swap(t_stack *a, t_stack *b);
void	stack_init(t_stack *list);
void	stack_push_back_n_make_array(t_stack *list, int *arr, int data);
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
void	sort_only_three_in_a(t_stack *a);
void	sort_the_others(t_stack *a, t_stack *b);
void	get_min_rotate(t_stack *a, t_stack *b, int *i, int *j);
void	ft_check_array_sort(int *arr, int size, int idx);
void	ft_sort_three_division(t_stack *a, t_stack *b);
void	ft_sort_3div_insruct(t_stack *a, t_stack *b, int pivot1, int pivot2);
int		set_a_location(t_stack *a, int num);
int		get_stack_min(t_node *node);
int		set_a_location_min(t_stack *a);
int		get_stack_max(t_node *node);
int		set_a_location_max(t_stack *a);
int		set_a_location_mid(int num, t_stack *a);
int		ft_get_bigger(int i, int j, int a_loc, int b_loc);
void	ft_rotate_same(t_stack *a, t_stack *b, int *i, int *j);
void	ft_rotate_a(t_stack *a, int i);
void	ft_rotate_b(t_stack *b, int j);
void	ft_sort_big_last_a(t_stack *a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:43:19 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 20:34:56 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 10000

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
void	exception(int checker, int *arr, int size);
void	ft_sort_three_division(t_stack *a, t_stack *b);
void	ft_sort_3div_insruct(t_stack *a, t_stack *b, int pivot1, int pivot2);
void	preprocess(char **argv, int *size, t_stack *a, int *arr);
int		set_a_location(t_stack *a, int num, int min, int max);
int		get_stack_min(t_node *node);
int		get_stack_max(t_node *node);
int		set_a_location_min(t_stack *a, int min);
int		set_a_location_max(t_stack *a, int max);
int		set_a_location_mid(t_stack *a, int num);
int		ft_get_bigger(int i, int j, int a_idx, int b_idx);
void	ft_rotate_same(t_stack *a, t_stack *b, int *i, int *j);
void	ft_rotate_a(t_stack *a, int i);
void	ft_rotate_b(t_stack *b, int j);
void	ft_sort_big_last_a(t_stack *a);
void	free_machine(t_stack *stack);
void	execute_rr(t_stack *stack);

char	*get_next_line(int fd);
void	preprocess_bonus(char **argv, int *size, t_stack *a);
void	check_function(char *str, t_stack *a, t_stack *b);
void	stack_push_back_n_make_array_bonus(t_stack *list, int data);
int		is_sorted(t_stack *a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:22:22 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 20:01:37 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_min_rotate(t_stack *a, t_stack *b, int *i, int *j)
{
	t_get_min_rotate_variables	v;
	t_node						*stack_b;

	v.index = 0;
	stack_b = b->head;
	v.min = get_stack_min(a->head);
	v.max = get_stack_max(a->head);
	while (v.index < b->num_node)
	{
		v.num = stack_b->val;
		v.a_idx = set_a_location(a, v.num, v.min, v.max);
		if (v.index >= (b->num_node + 1) / 2)
			v.b_idx = (b->num_node - v.index) * -1;
		else
			v.b_idx = v.index;
		if (v.index == 0 || ft_get_bigger(*i, *j, v.a_idx, v.b_idx))
		{
			*i = v.a_idx;
			*j = v.b_idx;
		}
		stack_b = stack_b->next;
		v.index++;
	}
}

void	ft_sort_three_division(t_stack *a, t_stack *b)
{
	int	i;
	int	pivot1;
	int	pivot2;

	i = a->num_node / 3;
	pivot1 = a->arr[i];
	i = a->num_node * 2 / 3;
	pivot2 = a->arr[i];
	i = a->num_node;
	while (i)
	{
		ft_sort_3div_insruct(a, b, pivot1, pivot2);
		i--;
	}
}

void	ft_sort_3div_insruct(t_stack *a, t_stack *b, int pivot1, int pivot2)
{
	if (a->head->val < pivot1)
	{
		pb(a, b);
		rb(b);
	}
	else if (a->head->val < pivot2)
		pb(a, b);
	else
		ra(a);
}

int	ft_get_bigger(int i, int j, int a_idx, int b_idx)
{
	if (i < 0)
		i = i * -1;
	if (j < 0)
		j = j * -1;
	if (a_idx < 0)
		a_idx = a_idx * -1;
	if (b_idx < 0)
		b_idx = b_idx * -1;
	if (i + j > a_idx + b_idx)
		return (1);
	else
		return (0);
}

void	ft_sort_big_last_a(t_stack *a)
{
	int	min;
	int	idx;

	min = get_stack_min(a->head);
	idx = set_a_location_min(a, min);
	while (idx)
	{
		if (idx > 0)
		{
			ra(a);
			idx--;
		}
		else
		{
			rra(a);
			idx++;
		}
	}
}

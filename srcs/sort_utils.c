/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:22:22 by jshin             #+#    #+#             */
/*   Updated: 2022/07/12 02:50:20 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_min_rotate(t_stack *a, t_stack *b, int *i, int *j)
{
	int			a_location;
	int			b_location;
	int			index;
	t_node		*stack_b;
	int			num;

	index = 0;
	stack_b = b->head;
	while (index < b->num_node)
	{
		num = stack_b->val;
		a_location = set_a_location(a, num);
		if (index >= (b->num_node + 1) / 2)
			b_location = (b->num_node - index) * -1;
		else
			b_location = index;
		if (index == 0 || ft_get_bigger(*i, *j, a_location, b_location))
		{
			*i = a_location;
			*j = b_location;
		}
		stack_b = stack_b->next;
		index++;
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

int	ft_get_bigger(int i, int j, int a_loc, int b_loc)
{
	if (i < 0)
		i = i * -1;
	if (j < 0)
		j = j * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (i + j > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	ft_sort_big_last_a(t_stack *a)
{
	int	min_location;

	min_location = set_a_location_min(a);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(a);
			min_location--;
		}
		else
		{
			rra(a);
			min_location++;
		}
	}
}

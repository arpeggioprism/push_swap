/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:16:11 by jshin             #+#    #+#             */
/*   Updated: 2022/07/08 07:58:10 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_only_three_in_a(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->head->val;
	mid = a->head->next->val;
	bottom = a->head->next->next->val;
	if (top > mid && mid > bottom && top > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && bottom > mid && top > bottom)
		ra(a);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && bottom > mid && bottom > top)
		sa(a);
	else if (mid > top && mid > bottom && top > bottom)
		rra(a);
}

void	sort_the_others(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	ft_sort_three_division(a, b);
	while (a->num_node > 3)
		pb(a, b);
	if (a->num_node == 2 && a->head->val > a->head->next->val)
			sa(a);
	if (a->num_node == 3)
		sort_only_three_in_a(a);
	while (b->num_node)
	{
		i = 0;
		j = 0;
		get_min_rotate(a, b, &i, &j);
		ft_rotate_same(a, b, &i, &j);
		ft_rotate_a(a, i);
		ft_rotate_b(b, j);
		pa(a, b);
	}
	ft_sort_big_last_a(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:34:19 by jshin             #+#    #+#             */
/*   Updated: 2022/07/07 01:30:22 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int top_a;
	int i;
	int ttemp;
	int temp[1000];
	int	fix;

	top_a = stack_peek(a);
	i = 0;
	temp[i] = a->num_node; 
	a->mid = (a->max + a->min) / 2;
	printf("a->max: %d, a->mid: %d, a->min:%d\n",a->max, a->mid, a->min);

	i = 0;
	while (temp[i]--)
	{
		if (stack_peek(a) > a->mid)
			ra(a);
		else if (b->num_node > 1)
		{
			is_max_min(b, top_a);
			fix++;
			if (pb(a, b) < b->head->next->val && b->mid > top_a)
				rb(b);
			else if (b->head->next->val > top_a && b->mid < top_a)
				sb(b);
		}
		else if (b->num_node == 1)
		{
			is_max_min(b, top_a);
			fix++;
			if (pb(a, b) < b->head->next->val)
				rb(b);
		}
		else
		{
			is_max_min(b, top_a);
			fix++;
			pb(a, b);
		}
		if (a->num_node == 0)
			break;
		if (temp[i] == 0)
		{
			b->head->first_part = fix;
			fix = 0;
			i++;
		}
	}
}

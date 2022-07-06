/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:16:11 by jshin             #+#    #+#             */
/*   Updated: 2022/07/07 01:31:55 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_only_three(t_stack *a)
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

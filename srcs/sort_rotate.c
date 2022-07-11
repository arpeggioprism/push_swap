/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:56:56 by jshin             #+#    #+#             */
/*   Updated: 2022/07/11 13:04:09 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	set_a_location(t_stack *a, int num)
{
	int	ret;

	if (num < get_stack_min(a->head))
		ret = set_a_location_min(a);
	else if (num > get_stack_max(a->head))
		ret = set_a_location_max(a);
	else
		ret = set_a_location_mid(num, a);
	return (ret);
}

void	ft_rotate_same(t_stack *a, t_stack *b, int *i, int *j)
{
	while (*i && *j && (*i > 0 && *j > 0))
	{
		rr(a, b);
		*i = *i - 1;
		*j = *j - 1;
	}
	while (*i && *j && (*i < 0 && *j < 0))
	{
		rrr(a, b);
		*i = *i + 1;
		*j = *j + 1;
	}
}

void	ft_rotate_a(t_stack *a, int i)
{
	while (i)
	{
		if (i > 0)
		{
			ra(a);
			i--;
		}
		else
		{
			rra(a);
			i++;
		}
	}
}

void	ft_rotate_b(t_stack *b, int j)
{
	while (j)
	{
		if (j > 0)
		{
			rb(b);
			j--;
		}
		else
		{
			rrb(b);
			j++;
		}
	}
}

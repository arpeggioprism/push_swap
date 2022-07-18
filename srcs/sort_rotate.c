/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:56:56 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 20:00:26 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	set_a_location(t_stack *a, int num, int min, int max)
{
	int	idx;

	if (num < min)
		idx = set_a_location_min(a, min);
	else if (num > max)
		idx = set_a_location_max(a, max);
	else
		idx = set_a_location_mid(a, num);
	return (idx);
}

void	ft_rotate_same(t_stack *a, t_stack *b, int *i, int *j)
{
	while (*i && *j && (*i > 0 && *j > 0))
	{
		rr(a, b);
		(*i)--;
		(*j)--;
	}
	while (*i && *j && (*i < 0 && *j < 0))
	{
		rrr(a, b);
		(*i)++;
		(*j)++;
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

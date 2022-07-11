/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:34:19 by jshin             #+#    #+#             */
/*   Updated: 2022/07/11 12:56:48 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->num_node == 2 && a->head->val > a->head->next->val)
			sa(a);
	else if (a->num_node == 3)
		sort_only_three_in_a(a);
	else
		sort_the_others(a, b);
}

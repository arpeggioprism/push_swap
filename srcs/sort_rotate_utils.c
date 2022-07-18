/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:32:41 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 19:18:04 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_min(t_node *node)
{
	int	min;

	min = node->val;
	while (node)
	{
		if (min > node->val)
			min = node->val;
		node = node->next;
	}
	return (min);
}

int	set_a_location_min(t_stack *a, int min)
{
	int		idx;
	int		tmp;
	t_node	*stack_a;

	idx = 0;
	tmp = 0;
	stack_a = a->head;
	while (stack_a)
	{
		tmp = stack_a->val;
		if (tmp == min)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	if (idx >= (a->num_node + 1) / 2)
		idx = (a->num_node - idx) * -1;
	return (idx);
}

int	get_stack_max(t_node *node)
{
	int	ret;

	ret = node->val;
	while (node)
	{
		if (ret < node->val)
			ret = node->val;
		node = node->next;
	}
	return (ret);
}

int	set_a_location_max(t_stack *a, int max)
{
	int		idx;
	int		tmp;
	t_node	*stack_a;

	idx = 0;
	tmp = 0;
	stack_a = a->head;
	while (stack_a)
	{
		tmp = stack_a->val;
		if (tmp == max)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	idx++;
	if (idx >= (a->num_node + 1) / 2)
		idx = (a->num_node - idx) * -1;
	return (idx);
}

int	set_a_location_mid(t_stack *a, int num)
{
	t_node	*stack_a;
	int		idx;

	stack_a = a->head;
	idx = 1;
	while (stack_a->next)
	{
		if (num > stack_a->val && num < stack_a->next->val)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	if (idx >= (a->num_node + 1) / 2)
		idx = (a->num_node - idx) * -1;
	return (idx);
}

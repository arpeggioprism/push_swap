/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:32:41 by jshin             #+#    #+#             */
/*   Updated: 2022/07/08 07:36:41 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_min(t_node *node)
{
	int	ret;

	ret = node->val;
	while (node)
	{
		if (ret > node->val)
		{
			ret = node->val;
		}
		node = node->next;
	}
	return (ret);
}

int	set_a_location_min(t_stack *a)
{
	int			ret;
	int			index;
	int			tmp;
	t_node		*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = a->head;
	index = get_stack_min(stack_a);
	while (stack_a)
	{
		tmp = stack_a->val;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (a->num_node + 1) / 2)
		ret = (a->num_node - ret) * -1;
	return (ret);
}

int	get_stack_max(t_node *node)
{
	int	ret;

	ret = node->val;
	while (node)
	{
		if (ret < node->val)
		{
			ret = node->val;
		}
		node = node->next;
	}
	return (ret);
}

int	set_a_location_max(t_stack *a)
{
	int			ret;
	int			index;
	int			tmp;
	t_node	*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = a->head;
	index = get_stack_max(stack_a);
	while (stack_a)
	{
		tmp = stack_a->val;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	ret++;
	if (ret >= (a->num_node + 1) / 2)
		ret = (a->num_node - ret) * -1;
	return (ret);
}

int	set_a_location_mid(int num, t_stack *a)
{
	t_node	*stack_a;
	int			ret;

	stack_a = a->head;
	ret = 1;
	while (stack_a->next)
	{
		if (num > stack_a->val && num < stack_a->next->val)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (a->num_node + 1) / 2)
		ret = (a->num_node - ret) * -1;
	return (ret);
}

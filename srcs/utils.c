/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:30:35 by jshin             #+#    #+#             */
/*   Updated: 2022/07/07 01:30:38 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_max_min_main(t_stack *list, t_node *new_node, int data)
{
	if (!list)
		return ;
	if (list->max < data)
		list->max = data;
	if (list->min > data)
		list->min = data;
}

void	is_max_min(t_stack *list, int data)
{
	if (!list)
		return ;
	if (list->max < data)
		list->max = data;
	if (list->min > data)
		list->min = data;
	list->mid = (list->max + list->min) / 2;
}

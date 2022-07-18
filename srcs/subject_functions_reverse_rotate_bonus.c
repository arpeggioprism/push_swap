/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_functions_reverse_rotate_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:34:27 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 16:54:45 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *a)
{
	t_node	*temp;

	if (!a || (a->num_node <= 1))
		return ;
	temp = a->tail;
	a->tail = a->tail->pre;
	temp->pre = NULL;
	a->tail->next = NULL;
	temp->next = a->head;
	a->head->pre = temp;
	a->head = temp;
	a->head->pre = NULL;
}

void	rrb(t_stack *b)
{
	t_node	*temp;

	if (!b || (b->num_node <= 1))
		return ;
	temp = b->tail;
	b->tail = b->tail->pre;
	temp->pre = NULL;
	b->tail->next = NULL;
	temp->next = b->head;
	b->head->pre = temp;
	b->head = temp;
	b->head->pre = NULL;
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*temp;
	int		i;

	if ((!a && !b) || (a->num_node < 2 && b->num_node < 2))
		return ;
	i = 0;
	while (i < 2)
	{
		if (a && (a->num_node > 1))
		{
			temp = a->tail;
			a->tail = a->tail->pre;
			temp->pre = NULL;
			a->tail->next = NULL;
			temp->next = a->head;
			a->head->pre = temp;
			a->head = temp;
			a->head->pre = NULL;
		}
		a = b;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_functions_reverse_roate.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:34:27 by jshin             #+#    #+#             */
/*   Updated: 2022/07/12 02:13:53 by jshin            ###   ########.fr       */
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
	write(1, "rra()\n", 6);
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
	write(1, "rrb()\n", 6);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr()\n", 6);
}

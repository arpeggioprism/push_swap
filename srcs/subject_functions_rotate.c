/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_functions_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:34:10 by jshin             #+#    #+#             */
/*   Updated: 2022/07/07 01:30:13 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;

	if (!a || (a->num_node <= 1))
		return ;
	temp = a->head;
	a->head = a->head->next;
	a->head->pre = NULL;
	a->tail->next = temp;
	temp->pre = a->tail->next;
	a->tail = temp;
	a->tail->next = NULL;
	write(1, "ra()\n", 5);
}

void	rb(t_stack *b)
{
	t_node	*temp;

	if (!b || (b->num_node <= 1))
		return ;
	temp = b->head;
	b->head = b->head->next;
	b->head->pre = NULL;
	b->tail->next = temp;
	b->tail = temp;
	b->tail->next = NULL;
	write(1, "rb()\n", 5);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr()\n", 5);
}

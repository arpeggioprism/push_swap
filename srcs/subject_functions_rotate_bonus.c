/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_functions_rotate_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:34:10 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 17:00:56 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	execute_rr(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	stack->head = stack->head->next;
	if (stack->num_node == 2)
		stack->head->next = temp;
	else
		stack->tail->next = temp;
	temp->next = NULL;
	if (stack->num_node == 2)
		temp->pre = stack->head;
	else
		temp->pre = stack->tail;
	stack->tail = temp;
	stack->head->pre = NULL;
}

void	ra(t_stack *a)
{
	t_node	*temp;

	if (!a || (a->num_node <= 1))
		return ;
	temp = a->head;
	a->head = a->head->next;
	if (a->num_node == 2)
		a->head->next = temp;
	else
		a->tail->next = temp;
	temp->next = NULL;
	if (a->num_node == 2)
		temp->pre = a->head;
	else
		temp->pre = a->tail;
	a->tail = temp;
	a->head->pre = NULL;
}

void	rb(t_stack *b)
{
	t_node	*temp;

	if (!b || (b->num_node <= 1))
		return ;
	temp = b->head;
	b->head = b->head->next;
	if (b->num_node == 2)
		b->head->next = temp;
	else
		b->tail->next = temp;
	temp->next = NULL;
	if (b->num_node == 2)
		temp->pre = b->head;
	else
		temp->pre = b->tail;
	b->tail = temp;
	b->head->pre = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	if ((!a && !b) || (a->num_node < 2 && b->num_node < 2))
		return ;
	if (a && (a->num_node > 1))
		execute_rr(a);
	if (b && (b->num_node > 1))
		execute_rr(b);
}

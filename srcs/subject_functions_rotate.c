/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_functions_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:34:10 by jshin             #+#    #+#             */
/*   Updated: 2022/07/14 03:43:05 by jshin            ###   ########.fr       */
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*temp;
	int		i;

	if (!a || !b || (a->num_node < 2) || (b->num_node < 2))
		return ;
	i = 0;
	while (i < 2)
	{
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
		a = b;
		i++;
	}
	write(1, "rr\n", 3);
}

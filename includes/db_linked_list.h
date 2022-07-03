/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:41 by jshin             #+#    #+#             */
/*   Updated: 2022/07/04 02:19:00 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_LINKED_LIST_H
# define DB_LINKED_LIST_H

# include "push_swap.h"

typedef struct s_node
{
	int				val;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

typedef struct s_db_linked_list
{
	int		num_node;
	t_node	*head;
	t_node	*cur;
	t_node	*tail;
}	t_stack;

void	stack_init(t_stack *list)
{
	if (!list)
		return ;
	list->num_node = 0;
	list->head = NULL;
	list->cur = NULL;
	list->tail = NULL;
}

void	stack_push_back(t_stack *list, int data)
{
	t_node	*new_node;

	if (!list)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->val = data;
	if (list->head)
	{
		list->tail->next = new_node;
		new_node->pre = list->tail;
	}
	else
	{
		list->head = new_node;
		list->cur = new_node;
		list->tail = new_node;
		new_node->pre = NULL;
	}
	list->tail = new_node;
	new_node->next = NULL;
	list->num_node += 1;
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*new_node;
	t_node	*temp;

	if (!a && !b && !b->head)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->val = b->head->val;
	temp = b->head;
	b->head = b->head->next;
	if (!b->head)
	{
		b->cur = NULL;
		b->tail = NULL;
	}
	else
		b->cur = b->head->next;
	free(temp);
	b->num_node -= 1;
	new_node->next = a->head;
	if (a->head)
		a->head->pre = new_node;
	a->head = new_node;
	a->cur = new_node;
	new_node->pre = NULL;
	a->num_node += 1;
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*new_node;
	t_node	*temp;

	if (!a && !b && !a->head)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->val = a->head->val;
	temp = a->head;
	a->head = a->head->next;
	if (!a->head)
	{
		a->cur = NULL;
		a->tail = NULL;
	}
	else
		a->cur = a->head->next;
	free(temp);
	a->num_node -= 1;
	new_node->next = b->head;
	if (b->head)
		b->head->pre = new_node;
	b->head = new_node;
	b->cur = new_node;
	new_node->pre = NULL;
	b->num_node += 1;
}

#endif

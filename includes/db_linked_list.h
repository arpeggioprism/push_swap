/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:41 by jshin             #+#    #+#             */
/*   Updated: 2022/07/04 16:26:41 by jshin            ###   ########.fr       */
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

int	stack_peek(t_stack *stack)
{
	if (!stack || (stack->num_node <= 0))
		return -1;
	return stack->head->val;
}

void	stack_pop(t_stack *stack)
{
	t_node	*temp;

	if (!stack || (stack->num_node <= 0))
		return ;
	temp = stack->head;
	stack->head = stack->head->next;
	if (!stack->head)
	{
		stack->cur = NULL;
		stack->tail = NULL;
	}
	else
		stack->cur = stack->head;
	free(temp);
	stack->num_node -= 1;
}

void	stack_push(t_stack *stack, int data)
{
	t_node *new_node;

	if (!stack)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->val = data;
	new_node->next = stack->head;
	if (stack->head)
		stack->head->pre = new_node;
	stack->head = new_node;
	stack->cur = new_node;
	new_node->pre = NULL;
	stack->num_node += 1;
}

void	pa(t_stack *a, t_stack *b)
{
	int	temp;

	if (!a || !b)
		return ;
	temp = stack_peek(b);
	if (temp == -1)
		return ;
	stack_pop(b);
	stack_push(a, temp);
}

void	pb(t_stack *a, t_stack *b)
{
	int	temp;

	if (!b || !a)
		return ;
	temp = stack_peek(a);
	if (temp == -1)
		return ;
	stack_pop(a);
	stack_push(b, temp);
}

void	sa(t_stack *a)
{
	int	temp;

	if (!a || (a->num_node <= 1))
		return ;
	temp = a->head->val;
	a->head->val = a->head->next->val;
	a->head->next->val = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (!b || (b->num_node <= 1))
		return ;
	temp = b->head->val;
	b->head->val = b->head->next->val;
	b->head->next->val = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

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
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

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
	b->tail->pre = NULL;
	temp = b->tail;
	b->tail = b->tail->pre;
	b->tail->next = NULL;
	temp->next = b->head;
	b->head->pre = temp;
	b->head = temp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

#endif

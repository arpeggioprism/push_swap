/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:41 by jshin             #+#    #+#             */
/*   Updated: 2022/07/04 04:06:47 by jshin            ###   ########.fr       */
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
	if (!stack || !stack->head)
		return -1;
	return stack->head->val;
}

void	stack_pop(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->head)
		return ;
	temp = stack->head;
	stack->head = stack->head->next;
	if (!stack->head)
	{
		stack->cur = NULL;
		stack->tail = NULL;
	}
	else
		stack->cur = stack->head->next;
	free(temp);
	stack->num_node -= 1;
}

void	stack_push(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node || !stack->head)
		return ;
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
	t_node	*new_node;

	if (!a || !b)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->val = stack_peek(b);
	stack_pop(b);
	stack_push(a, new_node);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*new_node;
	t_node	*temp;

	if (!a || !b)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->val = stack_peek(a);
	stack_pop(a);
	stack_push(b, new_node);
}

#endif

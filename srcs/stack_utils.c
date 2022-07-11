/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:30:02 by jshin             #+#    #+#             */
/*   Updated: 2022/07/12 02:13:55 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_init(t_stack *list)
{
	if (!list)
		return ;
	list->num_node = 0;
	list->head = NULL;
	list->cur = NULL;
	list->tail = NULL;
}

void	stack_push_back_n_make_array(t_stack *list, int *arr, int data)
{
	t_node	*new_node;
	int		i;

	if (!list)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->val = data;
	*arr = data;
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

double	stack_peek(t_stack *stack)
{
	if (!stack || (stack->num_node <= 0))
		return (99999999999);
	return (stack->head->val);
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
	{
		stack->cur = stack->head;
		stack->head->pre = NULL;
	}
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
	if (stack->num_node == 1)
	{
		stack->tail = stack->head;
		stack->tail->next = NULL;
	}
}

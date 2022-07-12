/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_functions_push_swap.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:34:12 by jshin             #+#    #+#             */
/*   Updated: 2022/07/12 19:06:19 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

double	pa(t_stack *a, t_stack *b)
{
	int	temp;

	if (!a || !b)
		return (99999999999);
	temp = stack_peek(b);
	if (temp == -1)
		return (99999999999);
	stack_pop(b);
	stack_push(a, temp);
	write(1, "pa\n", 3);
	return (temp);
}

double	pb(t_stack *a, t_stack *b)
{
	int	temp;

	if (!b || !a)
		return (99999999999);
	temp = stack_peek(a);
	if (temp == -1)
		return (99999999999);
	stack_pop(a);
	stack_push(b, temp);
	write(1, "pb\n", 3);
	return (temp);
}

void	sa(t_stack *a)
{
	int	temp;

	if (!a || (a->num_node <= 1))
		return ;
	temp = a->head->val;
	a->head->val = a->head->next->val;
	a->head->next->val = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	if (!b || (b->num_node <= 1))
		return ;
	temp = b->head->val;
	b->head->val = b->head->next->val;
	b->head->next->val = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

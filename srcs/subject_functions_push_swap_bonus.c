/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_functions_push_swap_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:34:12 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 16:56:54 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

double	pa(t_stack *a, t_stack *b)
{
	double	temp;

	if (!a || !b)
		return (99999999999);
	temp = stack_peek(b);
	if (temp == 99999999999)
		return (99999999999);
	stack_pop(b);
	stack_push(a, (int)temp);
	return ((int)temp);
}

double	pb(t_stack *a, t_stack *b)
{
	double	temp;

	if (!b || !a)
		print_error();
	temp = stack_peek(a);
	if (temp == 99999999999)
		return (99999999999);
	stack_pop(a);
	stack_push(b, (int)temp);
	return ((int)temp);
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
	int	temp;

	if ((!a && !b) || (a->num_node < 2 && b->num_node < 2))
		return ;
	if (a && (a->num_node > 1))
	{
		temp = a->head->val;
		a->head->val = a->head->next->val;
		a->head->next->val = temp;
	}
	if (b && (b->num_node > 1))
	{
		temp = b->head->val;
		b->head->val = b->head->next->val;
		b->head->next->val = temp;
	}
}

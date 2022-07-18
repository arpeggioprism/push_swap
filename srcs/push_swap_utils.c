/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 04:01:10 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 17:11:08 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_machine(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	stack->cur = stack->head;
	while (stack->cur)
	{
		temp = stack->cur;
		stack->cur = stack->cur->next;
		free(temp);
	}
}

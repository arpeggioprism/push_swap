/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:41 by jshin             #+#    #+#             */
/*   Updated: 2022/07/07 01:30:51 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_LINKED_LIST_H
# define DB_LINKED_LIST_H

# include "push_swap.h"

typedef struct s_node
{
	int				val;
	int				first_part;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

typedef struct s_db_linked_list
{
	int		num_node;
	int		max;
	int		mid;
	int		min;
	t_node	*head;
	t_node	*cur;
	t_node	*tail;
}	t_stack;

#endif

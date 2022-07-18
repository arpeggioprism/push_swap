/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:41 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 20:01:11 by jshin            ###   ########.fr       */
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
	int		*arr;
	t_node	*head;
	t_node	*cur;
	t_node	*tail;
	int		num_node;
}	t_stack;

typedef struct s_v
{
	int		a_idx;
	int		b_idx;
	int		index;
	int		num;
	int		min;
	int		max;
}	t_get_min_rotate_variables;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:41 by jshin             #+#    #+#             */
/*   Updated: 2022/07/01 23:17:11 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_LINKED_LIST_H
# define DB_LINKED_LIST_H

# define TRUE 1
# define FALSE 0
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_node
{
	int				val;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

typedef struct	s_db_linked_list
{
	t_node	*head;
	t_node	*cur;
	int		num_node;
}	t_list;

void	list_init(t_list *list)
{
	list->head = NULL;
	list->cur = NULL;
	list->num_node = 0;
}

void	list_insert(t_list *list, int data)
{
	if (!list)
		return ;
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	new_node->val = data;
	new_node->next = list->head;
	if (list->head)
		list->head->pre = new_node;
	list->head = new_node;
	new_node->pre = NULL;
	list->num_val += 1;
}

#endif

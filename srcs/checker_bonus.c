/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:54:20 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 17:13:46 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	preprocess_bonus(char **argv, int *size, t_stack *a)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	j = 0;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ', size);
		j = 0;
		while (temp[j])
		{
			stack_push_back_n_make_array_bonus(a, ft_atoi(temp[j]));
			free(temp[j++]);
		}
		free(temp);
		i++;
	}
}

void	stack_push_back_n_make_array_bonus(t_stack *list, int data)
{
	t_node	*new_node;

	if (!list)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
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

void	check_function(char *str, t_stack *a, t_stack *b)
{
	if (ft_strnstr(str, "pa\n", 4))
		pa(a, b);
	else if (ft_strnstr(str, "pb\n", 4))
		pb(a, b);
	else if (ft_strnstr(str, "rra\n", 4))
		rra(a);
	else if (ft_strnstr(str, "rrb\n", 4))
		rrb(b);
	else if (ft_strnstr(str, "rrr\n", 4))
		rrr(a, b);
	else if (ft_strnstr(str, "ss\n", 4))
		ss(a, b);
	else if (ft_strnstr(str, "ra\n", 4))
		ra(a);
	else if (ft_strnstr(str, "rb\n", 4))
		rb(b);
	else if (ft_strnstr(str, "sa\n", 4))
		sa(a);
	else if (ft_strnstr(str, "sb\n", 4))
		sb(b);
	else if (ft_strnstr(str, "rr\n", 4))
		rr(a, b);
	else
		print_error();
}

int	is_sorted(t_stack *a)
{
	if (!a)
		return (0);
	a->cur = a->head;
	while (a->cur->next)
	{
		if (a->cur->val >= a->cur->next->val)
			return (0);
		a->cur = a->cur->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		size;
	char	*str;
	t_stack	a;
	t_stack	b;

	size = 0;
	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	preprocess_bonus(argv, &size, &a);
	str = get_next_line(0);
	while (str)
	{
		check_function(str, &a, &b);
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_machine(&a);
	free_machine(&b);
	return (0);
}

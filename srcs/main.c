/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:04:53 by jshin             #+#    #+#             */
/*   Updated: 2022/07/04 16:26:43 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print(t_stack *a, t_stack *b)
{
	printf("[a values] | [b values]\n");
	printf("\n");
	a->cur = a->head;
	while (a->cur)
	{
		printf("a: %d\n", a->cur->val);
		a->cur = a->cur->next;
	}
	printf("\n");
	b->cur = b->head;
	while (b->cur)
	{
		printf("b: %d\n", b->cur->val);
		b->cur = b->cur->next;
	}
	printf("\n");
	printf("a->num_node: %d\n", a->num_node);
	printf("\n");
	printf("b->num_node: %d\n", b->num_node);
	printf("\n");
	printf("-------------------------------------\n");
	printf("\n");
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**temp;
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	i = 1;
	j = 0;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
			stack_push_back(&a, ft_atoi(temp[j++]));
		i++;
	}

	print(&a, &b);
	rra(&a);
	printf("rra();\n\n");
	print(&a, &b);
	pb(&a, &b);
	printf("pb();\n\n");
	print(&a, &b);
	sa(&a);
	printf("sa();\n\n");
	print(&a, &b);
	rra(&a);
	printf("rra();\n\n");
	print(&a, &b);
	pa(&a, &b);
	printf("pa();\n\n");
	print(&a, &b);
	return (0);
}

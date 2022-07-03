/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:04:53 by jshin             #+#    #+#             */
/*   Updated: 2022/07/04 05:23:20 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	char **temp;

	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);

	i = 1;
	j = 0;
	k = 0;
	while(argv[i])
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while(temp[j])
		{
				stack_push_back(&a, ft_atoi(temp[j]));
				j++;
		}
		i++;
	}
	stack_push_back(&b, 1004);
	stack_push_back(&b, 1005);
	
	printf("[a values]\n");
	a.cur = a.head;
	while (a.cur)
	{
		printf("a: %d\n", a.cur->val);
		a.cur = a.cur->next;
	}
	printf("\n");
	printf("[b values]\n");
	b.cur = b.head;
	while (b.cur)
	{
		printf("b: %d\n", b.cur->val);
		b.cur = b.cur->next;
	}
	printf("\n");
	printf("a.num_node: %d\n", a.num_node);
	printf("\n");
	printf("b.num_node: %d\n", b.num_node);
	printf("\n");
	printf("-------------------------------------\n");
	printf("\n");
	pa(&a, &b);
	printf("pa()\n");
	printf("\n");
	printf("[a values]\n");
	a.cur = a.head;
	while (a.cur)
	{
		printf("a: %d\n", a.cur->val);
		a.cur = a.cur->next;
	}
	printf("\n");
	printf("[b values]\n");
	b.cur = b.head;
	while (b.cur)
	{
		printf("b: %d\n", b.cur->val);
		b.cur = b.cur->next;
	}
	printf("\n");
	printf("a.num_node: %d\n", a.num_node);
	printf("\n");
	printf("b.num_node: %d\n", b.num_node);
	printf("\n");
	printf("-------------------------------------\n");
	printf("\n");

	pb(&a, &b);
	printf("pb()\n");
	printf("\n");
	printf("[a values]\n");
	a.cur = a.head;
	while (a.cur)
	{
		printf("a: %d\n", a.cur->val);
		a.cur = a.cur->next;
	}
	printf("\n");
	printf("[b values]\n");
	b.cur = b.head;
	while (b.cur)
	{
		printf("b: %d\n", b.cur->val);
		b.cur = b.cur->next;
	}
	printf("\n");
	printf("a.num_node: %d\n", a.num_node);
	printf("\n");
	printf("b.num_node: %d\n", b.num_node);
	printf("\n");
	printf("-------------------------------------\n");
	printf("\n");

	pb(&a, &b);
	printf("pb()\n");
	printf("\n");
	printf("[a values]\n");
	a.cur = a.head;
	while (a.cur)
	{
		printf("a: %d\n", a.cur->val);
		a.cur = a.cur->next;
	}
	printf("\n");
	printf("[b values]\n");
	b.cur = b.head;
	while (b.cur)
	{
		printf("b: %d\n", b.cur->val);
		b.cur = b.cur->next;
	}
	printf("\n");
	printf("a.num_node: %d\n", a.num_node);
	printf("\n");
	printf("b.num_node: %d\n", b.num_node);
	stack_pop(&a);
	stack_pop(&a);
	stack_pop(&a);
	printf("stack_pop_a()\n");
	printf("stack_pop_a()\n");
	printf("stack_pop_a()\n");
	printf("\n");
	stack_pop(&b);
	stack_pop(&b);
	stack_pop(&b);
	stack_pop(&b);
	printf("stack_pop_b()\n");
	printf("stack_pop_b()\n");
	printf("stack_pop_b()\n");
	printf("stack_pop_b()\n");
	printf("\n");
	printf("[a values]\n");
	a.cur = a.head;
	while (a.cur)
	{
		printf("a: %d\n", a.cur->val);
		a.cur = a.cur->next;
	}
	printf("\n");
	printf("[b values]\n");
	b.cur = b.head;
	while (b.cur)
	{
		printf("b: %d\n", b.cur->val);
		b.cur = b.cur->next;
	}
	printf("\n");
	printf("a.num_node: %d\n", a.num_node);
	printf("\n");
	printf("b.num_node: %d\n", b.num_node);
	return (0);
}

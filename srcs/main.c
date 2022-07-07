/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:04:53 by jshin             #+#    #+#             */
/*   Updated: 2022/07/08 08:33:56 by jshin            ###   ########.fr       */
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

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		size;
	int		arr[argc - 1];
	char	**temp;
	t_stack	a;
	t_stack	b;

	size = 0;
	if (argc < 2)
		print_error();

	stack_init(&a);
	stack_init(&b);
	i = 1;
	j = 0;
	k = 0;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ', &size);
		j = 0;
		while (temp[j])
			stack_push_back_n_make_array(&a, &arr[k++], ft_atoi(temp[j++]));
		i++;
	}
	ft_check_array_sort(arr, size, 0);
	a.arr = arr;
	print(&a, &b);
	push_swap(&a, &b);
	print(&a, &b);
	
	return (0);
}

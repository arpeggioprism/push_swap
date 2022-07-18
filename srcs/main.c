/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:04:53 by jshin             #+#    #+#             */
/*   Updated: 2022/07/18 20:40:36 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	preprocess(char **argv, int *size, t_stack *a, int *arr)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = 1;
	j = 0;
	k = 0;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ', size);
		j = 0;
		while (temp[j])
		{
			stack_push_back_n_make_array(a, &arr[k++], ft_atoi(temp[j]));
			free(temp[j++]);
		}
		free(temp);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		size;
	int		arr[99999];
	t_stack	a;
	t_stack	b;

	size = 0;
	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	preprocess(argv, &size, &a, arr);
	ft_check_array_sort(arr, size, 0);
	a.arr = arr;
	push_swap(&a, &b);
	free_machine(&a);
	free_machine(&b);
	return (0);
}

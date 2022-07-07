/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:35:52 by jshin             #+#    #+#             */
/*   Updated: 2022/07/07 17:36:11 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_array_sort(int *arr, int size, int idx)
{
	int	j;
	int	checker;
	int	tmp;

	checker = 0;
	while (idx < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				checker++;
			}
				j++;
		}
		if (arr[idx] == arr[idx + 1])
			print_error();
		idx++;
	}
	if (checker == 0)
		print_error();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:56:56 by jshin             #+#    #+#             */
/*   Updated: 2022/07/07 17:57:58 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	set_a_location(int num, t_info *info)
{
	int	ret;

	if (num < get_stack_min(info->top_a))
		ret = set_a_location_min(info);
	else if (num > get_stack_max(info->top_a))
		ret = set_a_location_max(info);
	else
		ret = set_a_location_mid(num, info);
	return (ret);
}

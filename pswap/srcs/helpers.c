/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:25 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/07 11:57:35 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ps_diff(int a, int b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

int	ps_minint(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	array_len(char **array)
{
	int	result;

	result = 0;
	while (*array)
	{
		result++;
		array++;
	}
	return (result);
}

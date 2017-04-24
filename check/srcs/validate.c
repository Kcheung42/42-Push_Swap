/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:08 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/20 12:07:42 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ch_is_dup(t_linklst *a, int argv)
{
	t_linklst	*tmp;

	tmp = a;
	while (tmp)
	{
		if (argv == tmp->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ch_check_input(t_operation *list, int n)
{
	while (n-- >= 0)
	{
		if (list[n] == invalid)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
	}
	return (1);
}

int		ch_is_solution(t_stack *result)
{
	t_linklst	*tmp;
	t_linklst	*prev;

	tmp = result->a_head;
	if (result->blen > 0)
		return (0);
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
		if (tmp->data < prev->data)
			return (0);
	}
	return (1);
}

void	ch_prnt_error(t_linklst *new, t_stack *ent, char **array, char *str)
{
	ft_putstr_fd(str, 2);
	free_ent(ent);
	free(new);
	if (array)
		free_line(array);
	exit(-1);
}

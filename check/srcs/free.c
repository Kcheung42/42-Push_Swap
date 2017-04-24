/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:20:51 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/21 19:21:23 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_ent(t_stack *ent)
{
	t_linklst	*cur;

	while ((cur = ent->a_head))
	{
		ent->a_head = ent->a_head->next;
		free(cur);
	}
	while ((cur = ent->b_head))
	{
		ent->b_head = ent->b_head->next;
		free(cur);
	}
	free(ent);
}

void	free_line(char **line)
{
	char **begin;

	begin = NULL;
	if (line)
	{
		begin = line;
		while (*begin)
		{
			free(*begin);
			begin++;
		}
		free(line);
	}
}

void	free_both(t_stack *ent, char **line)
{
	free_ent(ent);
	free_line(line);
}

void	main_error(t_stack *ent, char **line)
{
	free_both(ent, line);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

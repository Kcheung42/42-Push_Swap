/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:20:51 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/21 19:34:55 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	free_ent(t_stack *ent)
{
	t_linklst *cur;

	cur = ent->a_head;
	if (ent->a_head)
	{
		while ((cur = ent->a_head) != ent->a_end)
		{
			ent->a_head = ent->a_head->next;
			free(cur);
		}
		free(cur);
	}
	if (ent->b_head)
	{
		cur = ent->b_head;
		while ((cur = ent->b_head) != ent->b_end)
		{
			ent->b_head = ent->b_head->next;
			free(cur);
		}
		free(cur);
	}
	free(ent);
}

void	free_line(char **line)
{
	char **begin;

	begin = line;
	while (*line)
	{
		free(*line);
		line++;
	}
	free(begin);
}

void	free_both(t_stack *ent, char **line)
{
	free_ent(ent);
	free_line(line);
}

void	err_setstack(t_stack *ent, char **line)
{
	free(ent);
	free_line(line);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

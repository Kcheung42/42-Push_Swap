/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:30:54 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/06 21:30:56 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ch_operate_rra(t_stack *stacks)
{
	t_linklst	*temp;
	t_linklst	*prev;

	if (!stacks->a_head || stacks->alen == 1)
		return ;
	else
	{
		temp = stacks->a_head;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		temp->next = stacks->a_head;
		stacks->a_head = temp;
	}
}

void	ch_operate_rrb(t_stack *stacks)
{
	t_linklst	*temp;
	t_linklst	*prev;

	if (!stacks->b_head || stacks->blen == 1)
		return ;
	else
	{
		temp = stacks->b_head;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		temp->next = stacks->b_head;
		stacks->b_head = temp;
	}
}

void	ch_operate_rrr(t_stack *stacks)
{
	ch_operate_rra(stacks);
	ch_operate_rrb(stacks);
}

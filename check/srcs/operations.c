/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:29:38 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/06 21:29:40 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ch_operate_sa(t_stack *stacks)
{
	t_linklst	*temp;

	if (!stacks->a_head || stacks->alen == 1)
		return ;
	else
	{
		temp = stacks->a_head;
		stacks->a_head = temp->next;
		temp->next = stacks->a_head->next;
		stacks->a_head->next = temp;
	}
}

void	ch_operate_sb(t_stack *stacks)
{
	t_linklst	*temp;

	if (!stacks->b_head || stacks->blen == 1)
		return ;
	else
	{
		temp = stacks->b_head;
		stacks->b_head = temp->next;
		temp->next = stacks->b_head->next;
		stacks->b_head->next = temp;
	}
}

void	ch_operate_ss(t_stack *stacks)
{
	ch_operate_sa(stacks);
	ch_operate_sb(stacks);
}

void	ch_operate_pa(t_stack *stacks)
{
	t_linklst	*temp;

	if (!stacks->b_head)
		return ;
	temp = stacks->b_head;
	stacks->b_head = temp->next;
	temp->next = stacks->a_head;
	stacks->a_head = temp;
	stacks->alen += 1;
	stacks->blen -= 1;
}

void	ch_operate_pb(t_stack *stacks)
{
	t_linklst	*temp;

	if (!stacks->a_head)
		return ;
	temp = stacks->a_head;
	stacks->a_head = temp->next;
	temp->next = stacks->b_head;
	stacks->b_head = temp;
	stacks->blen += 1;
	stacks->alen -= 1;
}

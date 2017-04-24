/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:30:45 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/06 21:30:46 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ch_operate_ra(t_stack *stacks)
{
	t_linklst	*temp;
	t_linklst	*first;

	if (!stacks->a_head || stacks->alen == 1)
		return ;
	else
	{
		temp = stacks->a_head;
		first = stacks->a_head;
		stacks->a_head = stacks->a_head->next;
		while (temp->next)
			temp = temp->next;
		first->next = temp->next;
		temp->next = first;
	}
}

void	ch_operate_rb(t_stack *stacks)
{
	t_linklst	*temp;
	t_linklst	*first;

	if (!stacks->b_head || stacks->blen == 1)
		return ;
	else
	{
		temp = stacks->b_head;
		first = stacks->b_head;
		stacks->b_head = stacks->b_head->next;
		while (temp->next)
			temp = temp->next;
		first->next = temp->next;
		temp->next = first;
	}
}

void	ch_operate_rr(t_stack *stacks)
{
	ch_operate_ra(stacks);
	ch_operate_rb(stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:44 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/10 13:41:22 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_fixlink_src(t_stack *stacks, t_linklst *node, t_operation op)
{
	t_linklst	*a_first;
	t_linklst	*a_last;

	a_first = (op == pa) ? stacks->a_head : stacks->b_head;
	a_last = (op == pa) ? stacks->a_end : stacks->b_end;
	if (a_first == a_last && a_first == NULL)
	{
		stacks->a_end = (op == pa) ? node : stacks->a_end;
		stacks->b_end = (op == pb) ? node : stacks->b_end;
	}
	else
	{
		a_last->next = node;
		node->prev = a_last;
		a_last = node;
		a_last->next = a_first;
		a_first->prev = a_last;
	}
	stacks->a_head = (op == pa) ? node : stacks->a_head;
	stacks->b_head = (op == pb) ? node : stacks->b_head;
}

void	new_amax_amin(t_stack *stacks, int newdata)
{
	if (stacks->a_head == stacks->a_end && stacks->a_head == NULL)
	{
		stacks->amin = newdata;
		stacks->amax = newdata;
	}
	else
	{
		if (newdata < stacks->amin)
			stacks->amin = newdata;
		else if (newdata > stacks->amax)
			stacks->amax = newdata;
	}
}

void	ps_operate_pa(t_stack *stacks)
{
	t_linklst	*node;

	node = stacks->b_head;
	if (stacks->blen == 0)
		return ;
	ft_printf("pa\n");
	stacks->op_count += 1;
	if (stacks->blen == 1)
	{
		stacks->b_head = NULL;
		stacks->b_end = NULL;
	}
	else
	{
		stacks->b_head = stacks->b_head->next;
		stacks->b_end->next = stacks->b_head;
		stacks->b_head->prev = stacks->b_end;
	}
	new_amax_amin(stacks, node->data);
	ps_fixlink_src(stacks, node, pa);
	stacks->alen += 1;
	stacks->blen -= 1;
}

void	new_bmax_bmin(t_stack *stacks, int newdata)
{
	if (stacks->b_head == stacks->b_end && stacks->b_head == NULL)
	{
		stacks->bmin = newdata;
		stacks->bmax = newdata;
	}
	else
	{
		if (newdata < stacks->bmin)
			stacks->bmin = newdata;
		else if (newdata > stacks->bmax)
			stacks->bmax = newdata;
	}
}

void	ps_operate_pb(t_stack *stacks)
{
	t_linklst	*node;

	node = stacks->a_head;
	if (stacks->alen == 0)
		return ;
	ft_printf("pb\n");
	stacks->op_count += 1;
	if (stacks->alen == 1)
	{
		stacks->a_head = NULL;
		stacks->a_end = NULL;
	}
	else
	{
		stacks->a_head = stacks->a_head->next;
		stacks->a_end->next = stacks->a_head;
		stacks->a_head->prev = stacks->a_end;
	}
	new_bmax_bmin(stacks, node->data);
	ps_fixlink_src(stacks, node, pb);
	stacks->blen += 1;
	stacks->alen -= 1;
}

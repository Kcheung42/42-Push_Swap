/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:32 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/10 16:07:30 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_operate_sa(t_stack *stacks)
{
	t_linklst	*temp;

	if (!stacks->a_head || stacks->alen == 1)
		return ;
	ft_printf("sa\n");
	stacks->op_count += 1;
	if (stacks->alen == 2)
	{
		temp = stacks->a_head;
		stacks->a_head = stacks->a_end;
		stacks->a_end = temp;
	}
	else
	{
		temp = stacks->a_head;
		stacks->a_head = temp->next;
		stacks->a_head->next->prev = temp;
		temp->next = stacks->a_head->next;
		temp->prev = stacks->a_head;
		stacks->a_head->next = temp;
		stacks->a_head->prev = stacks->a_end;
		stacks->a_end->next = stacks->a_head;
	}
}

void	ps_operate_sb(t_stack *stacks)
{
	t_linklst	*temp;

	if (!stacks->b_head || stacks->blen == 1)
		return ;
	ft_printf("sb\n");
	stacks->op_count += 1;
	if (stacks->blen == 2)
	{
		temp = stacks->b_head;
		stacks->b_head = stacks->b_end;
		stacks->b_end = temp;
	}
	else
	{
		temp = stacks->b_head;
		stacks->b_head = temp->next;
		stacks->b_head->next->prev = temp;
		temp->next = stacks->b_head->next;
		temp->prev = stacks->b_head;
		stacks->b_head->next = temp;
		stacks->b_head->prev = stacks->b_end;
		stacks->b_end->next = stacks->b_head;
	}
}

void	ps_operate_ss(t_stack *stacks)
{
	ft_printf("ss\n");
	stacks->op_count += 1;
	ps_operate_sa(stacks);
	ps_operate_sb(stacks);
}

void	ps_operate_ra(t_stack *stacks)
{
	if (!stacks->a_head || stacks->alen == 1)
		return ;
	else
	{
		ft_printf("ra\n");
		stacks->op_count += 1;
		stacks->a_end = stacks->a_head;
		stacks->a_head = stacks->a_head->next;
	}
}

void	ps_operate_rb(t_stack *stacks)
{
	if (!stacks->b_head || stacks->blen == 1)
		return ;
	else
	{
		ft_printf("rb\n");
		stacks->op_count += 1;
		stacks->b_end = stacks->b_head;
		stacks->b_head = stacks->b_head->next;
	}
}

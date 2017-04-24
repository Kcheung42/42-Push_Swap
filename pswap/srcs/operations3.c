/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:55 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/06 21:31:57 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_operate_rr(t_stack *stacks)
{
	if ((!stacks->b_head || stacks->blen == 1) &&
			(!stacks->a_head || stacks->alen == 1))
		return ;
	ft_printf("rr\n");
	stacks->op_count += 1;
	if (stacks->a_head || stacks->alen > 1)
	{
		stacks->a_end = stacks->a_head;
		stacks->a_head = stacks->a_head->next;
	}
	if (stacks->b_head || stacks->blen > 1)
	{
		stacks->b_end = stacks->b_head;
		stacks->b_head = stacks->b_head->next;
	}
}

void	ps_operate_rra(t_stack *stacks)
{
	if (!stacks->a_head || stacks->alen == 1)
		return ;
	ft_printf("rra\n");
	stacks->op_count += 1;
	stacks->a_head = stacks->a_end;
	stacks->a_end = stacks->a_end->prev;
}

void	ps_operate_rrb(t_stack *stacks)
{
	if (!stacks->b_head || stacks->blen == 1)
		return ;
	ft_printf("rrb\n");
	stacks->op_count += 1;
	stacks->b_head = stacks->b_end;
	stacks->b_end = stacks->b_end->prev;
}

void	ps_operate_rrr(t_stack *stacks)
{
	if ((!stacks->a_head || stacks->alen == 1) &&
			(!stacks->b_head || stacks->blen == 1))
		return ;
	ft_printf("rrr\n");
	stacks->op_count += 1;
	if (stacks->a_head || stacks->alen > 1)
	{
		stacks->a_head = stacks->a_end;
		stacks->a_end = stacks->a_end->prev;
	}
	if (stacks->b_head || stacks->blen > 1)
	{
		stacks->b_head = stacks->b_end;
		stacks->b_end = stacks->b_end->prev;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:49:58 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/17 13:13:09 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	re_calc_aminmax(t_stack *ent)
{
	t_linklst	*temp;

	temp = ent->a_head;
	ent->amin = temp->data;
	ent->amax = temp->data;
	while (temp != ent->a_end)
	{
		if (temp->data > ent->amax)
			ent->amax = temp->data;
		else if (temp->data < ent->amin)
			ent->amin = temp->data;
		temp = temp->next;
	}
	if (temp->data > ent->amax)
		ent->amax = temp->data;
	else if (temp->data < ent->amin)
		ent->amin = temp->data;
}

void	reinsert(int count, t_stack *ent)
{
	while (count)
	{
		if (ent->b_head->data < ent->amin || ent->b_head->data > ent->amax)
		{
			while (ent->a_head->data != ent->amin)
				ps_rot_ra(ent->amin, ent) ? ps_execute(ra)(ent) :
					ps_execute(rra)(ent);
			ps_execute(pa)(ent);
		}
		else
		{
			while (!(ent->a_head->data > ent->b_head->data &&
						ent->a_end->data < ent->b_head->data))
				ps_execute(ra)(ent);
			ps_execute(pa)(ent);
		}
		count--;
	}
}

void	ps_sort_mini_a(t_stack *ent)
{
	int	i;

	i = 0;
	if (ent->a_head)
	{
		while (ent->alen > 3)
		{
			ps_execute(pb)(ent);
			i++;
		}
		re_calc_aminmax(ent);
		if (ent->a_head->data > ent->a_head->next->data)
			ps_execute(sa)(ent);
		if (ent->a_head->data != ent->amin)
			ps_execute(rra)(ent);
		else if (ent->a_end->data != ent->amax)
		{
			ps_execute(ra)(ent);
			ps_execute(sa)(ent);
		}
		reinsert(i, ent);
	}
}

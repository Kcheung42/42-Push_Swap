/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:49:04 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/21 17:36:20 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int		final_rot_rb(t_stack *stacks)
{
	size_t		dist_rb;
	size_t		direction;
	t_linklst	*temp;

	temp = stacks->b_head;
	dist_rb = 0;
	while (temp->data != stacks->bmax)
	{
		dist_rb++;
		temp = temp->next;
	}
	direction = (dist_rb <= stacks->blen / 2) ? 1 : 0;
	return (direction);
}

int		ps_optimal_pa(t_stack *stacks)
{
	t_linklst	*temp;
	size_t		distance;

	distance = 0;
	temp = stacks->a_head;
	while (!(temp->prev->data < stacks->b_head->data &&
				temp->data > stacks->b_head->data))
	{
		distance++;
		temp = temp->next;
	}
	if (distance <= stacks->alen / 2)
		return (1);
	else
		return (0);
}

void	ps_final_rot_ra(t_stack *ent)
{
	if (ent->b_head && ent->amax > ent->b_head->data)
	{
		while (!(ent->a_end->data < ent->b_head->data &&
					ent->a_head->data > ent->b_head->data))
			ps_optimal_pa(ent) ? ps_execute(ra)(ent) : ps_execute(rra)(ent);
	}
	else
	{
		while (ent->a_head->data != ent->amin)
			ps_execute(ra)(ent);
	}
}

void	ps_final_pa(t_stack *ent, int offset)
{
	while (ent->blen > 0)
	{
		while (ent->a_end->data > ent->b_head->data &&
					ent->a_end->data < ent->a_head->data)
			ps_execute(rra)(ent);
		ps_execute(pa)(ent);
	}
	(void)offset;
}

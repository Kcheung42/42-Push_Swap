/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:32:16 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/21 17:34:35 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ps_rot_ra(int target, t_stack *stacks)
{
	t_linklst	*temp;
	size_t		distance;

	distance = 0;
	temp = stacks->a_head;
	while (temp->data != target)
	{
		distance++;
		temp = temp->next;
	}
	if (distance <= stacks->alen / 2)
		return (1);
	else
		return (0);
}

int	ps_rot_rb(int target, t_stack *stacks)
{
	int			dist_rb;
	int			dist_rrb;
	int			direction;

	dist_rb = 0;
	dist_rrb = 0;
	if (target < stacks->bmin || target > stacks->bmax ||
			target == stacks->bmax)
		ps_dist_minmax(stacks, target, &dist_rb, &dist_rrb);
	else
		ps_dist_insert(stacks, target, &dist_rb, &dist_rrb);
	direction = (dist_rb <= dist_rrb) ? 1 : 0;
	return (direction);
}

int	calc_moves(t_stack *stacks, int target)
{
	int	dir_ra;
	int	dir_rb;
	int	movesa;
	int	movesb;

	dir_rb = ps_rot_rb(target, stacks);
	dir_ra = ps_rot_ra(target, stacks);
	movesa = ps_movesa(stacks, target);
	movesb = ps_movesb(stacks, target);
	if ((dir_rb && dir_ra) || (!dir_rb && !dir_ra))
		return (ps_minint(movesa, movesb) + ps_diff(movesa, movesb));
	return (movesa + movesb);
}

int	ps_min_moves(t_stack *stacks)
{
	int			guess;
	int			min_moves;
	int			cur_moves;
	t_linklst	*temp;

	temp = stacks->a_head;
	guess = temp->data;
	min_moves = ps_movesa(stacks, temp->data) + ps_movesb(stacks, temp->data);
	while (temp->next != stacks->a_head)
	{
		cur_moves = calc_moves(stacks, temp->data);
		if (cur_moves < min_moves)
		{
			min_moves = cur_moves;
			guess = temp->data;
		}
		temp = temp->next;
	}
	cur_moves = calc_moves(stacks, temp->data);
	if (cur_moves < min_moves)
	{
		min_moves = cur_moves;
		guess = temp->data;
	}
	return (guess);
}

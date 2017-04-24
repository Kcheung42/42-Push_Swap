/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:22 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/21 17:34:15 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int		ps_movesa(t_stack *stacks, int guess)
{
	size_t		distance;
	t_linklst	*temp;

	temp = stacks->a_head;
	distance = 0;
	while (temp->data != guess)
	{
		distance++;
		temp = temp->next;
	}
	if (distance > stacks->alen / 2)
		distance = stacks->alen - distance;
	return (distance);
}

void	ps_dist_insert(t_stack *stacks, int guess, int *dist_rb, int *dist_rrb)
{
	t_linklst	*temp;

	temp = stacks->b_head;
	while (!(temp->prev->data > guess && temp->data < guess))
	{
		*dist_rb += 1;
		temp = temp->next;
	}
	temp = stacks->b_head;
	while (!(temp->prev->data > guess && temp->data < guess))
	{
		*dist_rrb += 1;
		temp = temp->prev;
	}
}

void	ps_dist_minmax(t_stack *stacks, int guess, int *dist_rb, int *dist_rrb)
{
	t_linklst	*temp;

	temp = stacks->b_head;
	while (temp->data != stacks->bmax)
	{
		(*dist_rb)++;
		temp = temp->next;
	}
	temp = stacks->b_head;
	while (temp->data != stacks->bmax)
	{
		(*dist_rrb)++;
		temp = temp->prev;
	}
	(void)guess;
}

int		ps_movesb(t_stack *stacks, int guess)
{
	int			dist_rb;
	int			dist_rrb;
	int			min_move;
	t_linklst	*temp;

	temp = stacks->b_head;
	dist_rb = 0;
	dist_rrb = 0;
	min_move = 0;
	if (guess < stacks->bmin || guess > stacks->bmax)
		ps_dist_minmax(stacks, guess, &dist_rb, &dist_rrb);
	else
		ps_dist_insert(stacks, guess, &dist_rb, &dist_rrb);
	min_move = (dist_rb <= dist_rrb) ? dist_rb : dist_rrb;
	return (min_move);
}

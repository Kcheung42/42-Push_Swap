/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:21:38 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/24 14:37:50 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_pop(t_stack *stacks, int to_pop)
{
	while (stacks->a_head->data != to_pop)
	{
		if (ps_rot_ra(to_pop, stacks) && ps_rot_rb(to_pop, stacks))
			ps_execute(rr)(stacks);
		else if (ps_rot_ra(to_pop, stacks))
			ps_execute(ra)(stacks);
		else if (!ps_rot_ra(to_pop, stacks) && !ps_rot_rb(to_pop, stacks))
			ps_execute(rrr)(stacks);
		else
			ps_execute(rra)(stacks);
	}
	if (to_pop < stacks->bmin || to_pop > stacks->bmax)
	{
		while (stacks->b_head->data != stacks->bmax)
			ps_rot_rb(to_pop, stacks) ? ps_execute(rb)(stacks) :
				ps_execute(rrb)(stacks);
	}
	else
	{
		while (!(stacks->b_head->data < to_pop && stacks->b_end->data > to_pop))
			ps_rot_rb(to_pop, stacks) ? ps_execute(rb)(stacks) :
				ps_execute(rrb)(stacks);
	}
	ps_execute(pb)(stacks);
}

int		check(t_stack *env)
{
	t_linklst *temp;

	temp = env->a_head;
	while (temp->next != env->a_end)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	if (temp->data > temp->next->data)
		return (1);
	return (0);
}

void	push_swap(int argc, char **argv, int offset, t_stack *env)
{
	int			to_pop;

	ft_strchr(argv[1], ' ') ? ps_setstack1(argv, env) :
		ps_setstack2(argc, argv, env);
	if (!(argc == 1 || env->alen == 1 || !check(env)))
	{
		offset = env->alen > 100 ? 9 : 3;
		if (env->alen > 3)
			ps_execute(pb)(env);
		while ((int)env->alen > offset)
		{
			to_pop = ps_min_moves(env);
			ps_pop(env, to_pop);
		}
		while (env->b_head && env->b_head->data != env->bmax)
			(final_rot_rb(env)) ? ps_execute(rb)(env) : ps_execute(rrb)(env);
		ps_sort_mini_a(env);
		ps_final_rot_ra(env);
		ps_final_pa(env, offset);
		while (env->a_end->data < env->a_head->data)
			ps_execute(rra)(env);
	}
	free_ent(env);
}

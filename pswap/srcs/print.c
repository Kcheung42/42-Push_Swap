/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:32:19 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/06 21:32:20 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_prnt_stacks(t_stack *env)
{
	t_linklst	*tmpa;
	t_linklst	*tmpb;

	tmpa = env->a_head;
	tmpb = env->b_head;
	ft_printf("A |B\n");
	ft_printf("--|--\n");
	while ((tmpa && tmpa->next != env->a_head) ||
			(tmpb && tmpb->next != env->b_head))
	{
		(tmpa && tmpa->next != env->a_head) ? ft_printf("%d | ", tmpa->data) :
			ft_printf("  | ");
		tmpa = (tmpa && tmpa->next != env->a_head) ? tmpa->next : tmpa;
		if (tmpb && tmpb->next != env->b_head)
		{
			ft_printf("%d", tmpb->data);
			tmpb = tmpb->next;
		}
		ft_printf("\n");
	}
	(tmpa) ? ft_printf("%d | ", tmpa->data) : ft_printf("  | ");
	(tmpb) ? ft_printf("%d\n", tmpb->data) : ft_printf("\n");
	ft_printf("Result Operation count:%d\n", env->op_count);
}

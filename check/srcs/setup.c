/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:00 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/14 10:49:57 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ch_setup_ops(t_ops *operation)
{
	operation[0] = &ch_operate_sa;
	operation[1] = &ch_operate_sb;
	operation[2] = &ch_operate_ss;
	operation[3] = &ch_operate_pa;
	operation[4] = &ch_operate_pb;
	operation[5] = &ch_operate_ra;
	operation[6] = &ch_operate_rb;
	operation[7] = &ch_operate_rr;
	operation[8] = &ch_operate_rra;
	operation[9] = &ch_operate_rrb;
	operation[10] = &ch_operate_rrr;
}

t_operation		ch_convert(char *str)
{
	if (!strcmp(str, "sa"))
		return (sa);
	else if (!strcmp(str, "sb"))
		return (sb);
	else if (!strcmp(str, "ss"))
		return (ss);
	else if (!strcmp(str, "pa"))
		return (pa);
	else if (!strcmp(str, "pb"))
		return (pb);
	else if (!strcmp(str, "ra"))
		return (ra);
	else if (!strcmp(str, "rb"))
		return (rb);
	else if (!strcmp(str, "rr"))
		return (rr);
	else if (!strcmp(str, "rra"))
		return (rra);
	else if (!strcmp(str, "rrb"))
		return (rrb);
	else if (!strcmp(str, "rrr"))
		return (rrr);
	return (invalid);
}

t_ops			ch_execute(t_operation str)
{
	t_ops	*ch_operate_list;
	t_ops	ret;

	ch_operate_list = NULL;
	if (!ch_operate_list)
	{
		ch_operate_list = (t_ops *)malloc(sizeof(*ch_operate_list) * 11);
		ft_bzero(ch_operate_list, 9);
		ch_setup_ops(ch_operate_list);
	}
	ret = ch_operate_list[str];
	free(ch_operate_list);
	return (ret);
}

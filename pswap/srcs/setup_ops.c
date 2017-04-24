/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:32:23 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/12 11:44:07 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_setup_ops(t_ops *operation)
{
	operation[0] = &ps_operate_sa;
	operation[1] = &ps_operate_sb;
	operation[2] = &ps_operate_ss;
	operation[3] = &ps_operate_pa;
	operation[4] = &ps_operate_pb;
	operation[5] = &ps_operate_ra;
	operation[6] = &ps_operate_rb;
	operation[7] = &ps_operate_rr;
	operation[8] = &ps_operate_rra;
	operation[9] = &ps_operate_rrb;
	operation[10] = &ps_operate_rrr;
}

t_ops	ps_execute(t_operation str)
{
	t_ops	*op_list;
	t_ops	ret;

	op_list = NULL;
	if (!op_list)
	{
		if (!(op_list = (t_ops *)malloc(sizeof(*op_list) * 11)))
			return (NULL);
		ft_bzero(op_list, 10);
		ps_setup_ops(op_list);
	}
	ret = op_list[str];
	free(op_list);
	return (ret);
}

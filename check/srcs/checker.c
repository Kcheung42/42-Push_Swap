/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:21:34 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/23 16:25:43 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <fcntl.h>

void	ch_printlst(t_stack *env)
{
	t_linklst	*tmpa;
	t_linklst	*tmpb;

	tmpa = env->a_head;
	tmpb = env->b_head;
	printf("A |B\n");
	printf("--|--\n");
	while (tmpa || tmpb)
	{
		if (tmpa)
		{
			ft_printf("%d | ", tmpa->data);
			tmpa = tmpa->next;
		}
		else
			ft_printf("  | ");
		if (tmpb)
		{
			ft_printf("%d", tmpb->data);
			tmpb = tmpb->next;
		}
		ft_printf("\n");
	}
}

void	ch_valid_sol(t_stack *stacks)
{
	if (!ch_is_solution(stacks))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
}

char	*get_enum(t_operation op)
{
	if (op == sa)
		return ("sa");
	else if (op == sb)
		return ("sb");
	else if (op == ss)
		return ("ss");
	else if (op == pa)
		return ("pa");
	else if (op == pb)
		return ("pb");
	else if (op == ra)
		return ("ra");
	else if (op == rb)
		return ("rb");
	else if (op == rr)
		return ("rr");
	else if (op == rra)
		return ("rra");
	else if (op == rrb)
		return ("rrb");
	else if (op == rrr)
		return ("rrr");
	else
		return (NULL);
}

void	ch_runops(t_stack *stacks, int i, t_operation *oplist)
{
	int		j;
	char	*str;

	j = -1;
	while (++j < i)
	{
		ch_execute(oplist[j])(stacks);
		if (stacks->debug)
		{
			str = get_enum(oplist[j]);
			ft_printf("executing:%s\n", str);
			ch_printlst(stacks);
		}
	}
}

int		checker(int argc, char *argv[], t_stack *env)
{
	t_operation	oplist[100000];
	char		**line;
	int			i;
	int			err;

	err = 0;
	ft_strchr(argv[1], ' ') ? ch_makestack1(argc, argv, env) :
		ch_makestack2(argc, argv, env);
	line = (char **)malloc(sizeof(char *) * 100000);
	i = 0;
	while (get_next_line(0, &line[i]) > 0)
	{
		if (line[i] && (oplist[i] = ch_convert(line[i])) == invalid)
			err++;
		i++;
	}
	if (err)
		main_error(env, line);
	ch_runops(env, i, oplist);
	ch_valid_sol(env);
	free_both(env, line);
	return (0);
}

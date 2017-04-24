/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:32:27 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/24 14:32:56 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_linklst	*ps_lstnew(int d)
{
	t_linklst *new;

	if (!(new = (t_linklst*)malloc(sizeof(*new))))
		return (NULL);
	ft_bzero(new, sizeof(new));
	new->data = d;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ps_lstpush_end(t_stack *env, t_linklst *node)
{
	t_linklst	*first;
	t_linklst	*last;

	first = env->a_head;
	last = env->a_end;
	if (first == last && first == NULL)
	{
		env->a_head = node;
		env->a_end = node;
	}
	else
	{
		last->next = node;
		node->prev = last;
		last = node;
		env->a_end = last;
		first->prev = last;
		last->next = first;
		env->a_head = first;
	}
}

int			ps_is_dup(t_linklst *a, int argv)
{
	t_linklst	*tmp;

	tmp = a;
	if (!tmp)
		return (0);
	while (tmp && tmp->next != a)
	{
		if (argv == tmp->data)
			return (1);
		tmp = tmp->next;
	}
	if (tmp && argv == tmp->data)
		return (1);
	return (0);
}

void		ps_setstack1(char **argv, t_stack *env)
{
	t_linklst		*new;
	int				i;
	char			**arglist;
	int				arglen;

	arglist = ft_strsplit(argv[1], ' ');
	i = 0;
	arglen = array_len(arglist);
	while (i < arglen)
	{
		if (!(new = ps_lstnew(ft_atoi(arglist[i]))) ||
				(ft_strcmp(arglist[i], "0") && ft_atoi(arglist[i]) == 0) ||
				(ps_is_dup(env->a_head, ft_atoi(arglist[i]))))
			err_setstack(env, arglist);
		ps_lstpush_end(env, new);
		i++;
	}
	free_line(arglist);
	env->alen = i;
}

void		ps_setstack2(int argc, char **argv, t_stack *env)
{
	t_linklst		*new;
	int				i;

	i = 1;
	while (i < argc)
	{
		if (!(new = ps_lstnew(ft_atoi(argv[i]))) ||
				(ft_strcmp(argv[i], "0") && ft_atoi(argv[i]) == 0) ||
				(ps_is_dup(env->a_head, ft_atoi(argv[i]))))
		{
			free_ent(env);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		ps_lstpush_end(env, new);
		i++;
	}
	env->alen = i - 1;
}

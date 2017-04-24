/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:04 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/21 21:00:24 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_linklst	*ch_lstnew(int d)
{
	t_linklst *new;

	if (!(new = (t_linklst*)malloc(sizeof(*new))))
		return (NULL);
	ft_bzero(new, sizeof(new));
	new->data = d;
	new->next = NULL;
	return (new);
}

void		ch_lstpush_end(t_linklst **begin, t_linklst *node)
{
	t_linklst *temp;

	if (*begin == NULL)
	{
		node->next = *begin;
		*begin = node;
	}
	else
	{
		temp = *begin;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

int			array_len(char **array)
{
	int	result;

	result = 0;
	while (*array)
	{
		result++;
		array++;
	}
	return (result);
}

void		ch_makestack1(int argc, char **argv, t_stack *env)
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
		if (!(new = ch_lstnew(ft_atoi(arglist[i]))) ||
				(ft_strcmp(arglist[i], "0") && ft_atoi(arglist[i]) == 0) ||
				(ch_is_dup(env->a_head, ft_atoi(arglist[i]))))
			ch_prnt_error(new, env, arglist, "Error\n");
		ch_lstpush_end(&(env->a_head), new);
		i++;
	}
	if (argc == 3 && !ft_strcmp(argv[2], "-v"))
		env->debug = 1;
	free_line(arglist);
	env->alen = i;
}

void		ch_makestack2(int argc, char **argv, t_stack *env)
{
	t_linklst		*new;
	int				i;

	i = 1;
	while (i < argc)
	{
		if ((i == 1 || i == argc - 1) && !ft_strcmp(argv[i], "-v"))
			env->debug = 1;
		else if (!(new = ch_lstnew(ft_atoi(argv[i]))) ||
				(ft_strcmp(argv[i], "0") && ft_atoi(argv[i]) == 0) ||
				(ch_is_dup(env->a_head, ft_atoi(argv[i]))))
		{
			free_ent(env);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		else
			ch_lstpush_end(&(env->a_head), new);
		i++;
	}
	env->alen = i - 1;
}

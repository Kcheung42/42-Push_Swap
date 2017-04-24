/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:52:49 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/24 10:20:29 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	initiate_env(t_stack **env)
{
	*env = (t_stack *)malloc(sizeof(t_stack));
	(*env)->a_head = NULL;
	(*env)->b_head = NULL;
	(*env)->a_end = NULL;
	(*env)->b_end = NULL;
	(*env)->alen = 0;
	(*env)->blen = 0;
	(*env)->op_count = 0;
}

int		main(int argc, char **argv)
{
	int		offset;
	t_stack	*env;

	if (argc == 1)
		return (0);
	env = NULL;
	initiate_env(&env);
	offset = 3;
	push_swap(argc, argv, offset, env);
	return (0);
}

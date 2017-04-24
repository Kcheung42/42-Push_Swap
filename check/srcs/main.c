/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:46:22 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/23 16:48:02 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_env(t_stack **env)
{
	*env = (t_stack *)malloc(sizeof(t_stack));
	(*env)->a_head = NULL;
	(*env)->b_head = NULL;
	(*env)->alen = 0;
	(*env)->blen = 0;
	(*env)->debug = 0;
}

int		main(int argc, const char *argv[])
{
	t_stack	*env;

	if (argc == 1 || (!ft_strcmp(argv[1], "-v") && argc == 2))
		return (0);
	env = NULL;
	init_env(&env);
	checker(argc, (char**)argv, env);
	return (0);
}

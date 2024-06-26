/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:53:47 by aahlyel           #+#    #+#             */
/*   Updated: 2023/03/02 15:10:00 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_parse(t_list **garbg, t_stack *stack, char **av, int ac)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = NULL;
	while (i < ac)
	{
		j = -1;
		tmp = ft_split_garbg(av[i++], ' ', garbg);
		while (tmp[++j])
			new_node(garbg, stack, ft_atolld(garbg, tmp[j]), 0);
	}
	ft_check_dup(garbg, stack);
}

void	ft_check_dup(t_list **garbg, t_stack *stack)
{
	t_lst		*tmp;
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	while (i++ < stack->lenght)
	{
		j = i;
		tmp = stack->stack->next;
		while (j++ < stack->lenght)
		{
			if (tmp->content == stack->stack->content)
				ft_exit("Error", garbg, 0);
			tmp = tmp->next;
		}
		stack->stack = stack->stack->next;
	}
}

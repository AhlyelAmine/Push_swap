/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:57:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/21 18:52:13 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_sort(t_list **garbg, t_stack *a)
{
	int	ext;

	ext = 1;
	sort_check(garbg, a, &ext);
	if (a->lenght > 5)
		big_sort(garbg, a);
	else
		low_sort(&garbg, stack);
}

void	sort_check(t_list **garbg, t_stack *a, int *ext)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	while (i++ < a->lenght - 1)
	{
		tmp = a->stack->next;
		if (a->stack->content > tmp->content)
		{
			*ext = 1;
			return ;
		}
		a->stack = a->stack->next;
	}
	if (ext)
		ft_exit(NULL, garbg, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:26 by aahlyel           #+#    #+#             */
/*   Updated: 2022/11/30 19:18:51 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;

	new_node(stack_a, (*stack_b)->content);
	// (*stack_a) = (*stack_a)->prev;
	tmp = (*stack_b)->next;
	del_node(stack_b);
	*stack_b = tmp;
	rotate(stack_a);
}

void	push_b(t_lst **stack_b, t_lst **stack_a)
{
	t_lst	*tmp;

	new_node(stack_b, (*stack_a)->content);
	// (*stack_b) = (*stack_b)->prev;
	tmp = (*stack_a)->next;
	del_node(stack_a);
	*stack_a = tmp;
	rotate(stack_b);
}

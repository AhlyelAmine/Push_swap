/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:06:24 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/23 20:40:17 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

int		small_element(t_lst *stack)
{
	int		sml;
	int		i;

	sml = INT_MAX;
	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		sml = min(sml, stack->content);
		stack = stack->next;
	}
	return (sml);
}

int		high_element(t_lst *stack)
{
	int		bg;
	int		i;

	bg = INT_MIN;
	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		bg = max(bg, stack->content);
		stack = stack->next;
	}
	return (bg);
}

int		define_small(t_lst *stack, int min)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (i++ < stack->lenght.stack_len)
	{
		if (tmp->content == min)
		{
			tmp->parse_it = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (!(stack->lenght.stack_len % 2)
	&& (stack->lenght.stack_len / 2) >= i)
		return (1); // front front
	else if ((stack->lenght.stack_len % 2)
	&& (stack->lenght.stack_len / 2) + 1 >= i)
		return (1); // front front
	else
		return (0); // from back
}

int	check_place_in_a(t_lst *stack, int min)
{
	int	i;
	int	small;
	int	bg;

	i = 0;
	small = small_element(stack);
	bg = high_element(stack);
	if (min > bg)
		return (bg);
	if (min < small)
	{
		while (i < stack->lenght.stack_len)
		{
			if (stack->content == small)
				return (stack->prev->content);
			stack = stack->next;
			i++;
		}
	}
	while (i < stack->lenght.stack_len)
	{
		if (stack->content > min && min > stack->prev->content)
			return (stack->prev->content);
		stack = stack->next;
		i++;
	}
	return (0);
}

void	both_front(t_lst **stack_a, t_lst **stack_b, int ind)
{
	// int	i;

	// i = 0;
	// while (!((*stack_a)->prev->parse_it) && !((*stack_b)->parse_it))
	// {
	// 	rr(stack_a, stack_b);
	// 	i++;
	// }
	// while (!((*stack_a)->prev->parse_it))
	// 	rotate_a(stack_a, ind);
	// while (!((*stack_b)->parse_it))
	// 	rotate_a(stack_b, ind);
	// (*stack_a)->prev->parse_it = 0;
	// push_a(stack_a, stack_b);
	// (*stack_a)->parse_it = 0;
		int	i;

	i = 0;
	while (!((*stack_a)->parse_it) && !((*stack_b)->parse_it))
	{
		rr(stack_a, stack_b);
		i++;
	}
	while (!((*stack_a)->parse_it))
		rotate_a(stack_a, ind);
	while (!((*stack_b)->parse_it))
		rotate_a(stack_b, ind);
	(*stack_a)->parse_it = 0;
	push_a(stack_a, stack_b);
	(*stack_a)->parse_it = 0;
	swap_a(stack_a, 1);
}

void	both_back(t_lst **stack_a, t_lst **stack_b, int ind)
{
	int	i;

	i = 0;
	while (!((*stack_a)->prev->parse_it) && !((*stack_b)->parse_it))
	{
		rrr(stack_a, stack_b);
		i++;
	}
	while (!((*stack_a)->prev->parse_it))
		reverse_a(stack_a, ind);
	while (!((*stack_b)->parse_it))
		reverse_b(stack_b, ind);
	(*stack_a)->prev->parse_it = 0;
	push_a(stack_a, stack_b);
	(*stack_a)->parse_it = 0;
}

void	b_front_a_back(t_lst **stack_a, t_lst **stack_b, int ind)
{
	int	i;

	i = 0;

	while (!((*stack_b)->parse_it))
		rotate_b(stack_b, ind);
	i = 0;
	while (!((*stack_a)->prev->parse_it))
		reverse_a(stack_a, ind);
	(*stack_a)->prev->parse_it = 0;
	push_a(stack_a, stack_b);
	(*stack_a)->parse_it = 0;
}

void	a_front_b_back(t_lst **stack_a, t_lst **stack_b, int ind)
{
	// int	i;

	// i = 0;
	// while (!((*stack_a)->prev->parse_it))
	// 	rotate_a(stack_a, ind);
	// i = 0;
	// while (!((*stack_b)->parse_it))
	// 	reverse_b(stack_b, ind);
	// (*stack_a)->prev->parse_it = 0;
	// push_a(stack_a, stack_b);
	// (*stack_a)->parse_it = 0;
	int	i;

	i = 0;
	while (!((*stack_a)->parse_it))
		rotate_a(stack_a, ind);
	i = 0;
	while (!((*stack_b)->parse_it))
		reverse_b(stack_b, ind);
	(*stack_a)->parse_it = 0;
	push_a(stack_a, stack_b);
	(*stack_a)->parse_it = 0;
	swap_a(stack_a, 1);
}

void define_place(t_lst **stack_a, int	i, int ind)
{
	t_lst *tmp;
	int	j;

	j = 0;
	tmp = *stack_a;
	while (j++ < tmp->lenght.stack_len)
	{
		if (tmp->content == i)
		{
			tmp->parse_it = ind;
			break ;
		}
		tmp = tmp->next;
	}
}

void	init_parse_it(t_lst **stack)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (i++ < tmp->lenght.stack_len)
	{
		tmp->parse_it = 0;
		tmp = tmp->next;
	}
}

int		small_parse(t_lst *stack, int ind)
{
	int		sml;
	int		i;

	sml = INT_MAX;
	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		if (ind)
			sml = min(sml, stack->parse_it);
		else
			sml = min(sml, stack->parse_it_back);
		stack = stack->next;
	}
	return (sml);
}

int	define_min_back(t_lst *stack, int min_back)
{
	int	i;

	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		stack->parse_it = 0;
		rotate_a(&stack, 0);
	}
	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		if (stack->parse_it_back == min_back)
			break ;
		rotate_a(&stack, 0);
	}
	stack->parse_it = 1;
	return (stack->content);
}

int	define_min_front(t_lst *stack, int min_back)
{
	int	i;

	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		stack->parse_it = 0;
		rotate_a(&stack, 0);
	}
	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		if (stack->parse_it == min_back)
			break ;
		rotate_a(&stack, 0);
	}
	stack->parse_it = 1;
	return (stack->content);
}

int	stack_b_frontback(t_lst *stack, int content)
{
	int	i;

	i = 0;
	while (i++ < stack->lenght.stack_len)
	{
		if (stack->content == content)
			break ;
		rotate_b(&stack, 0);
	}
	if (!(stack->lenght.stack_len % 2)
	&& (stack->lenght.stack_len / 2) >= i)
		return (1); // front front
	else if ((stack->lenght.stack_len % 2)
	&& (stack->lenght.stack_len / 2) + 1 >= i)
		return (1); // front front
	else
		return (0); // from back
}

void	ft_sort_controller(t_lst *stack_a, int ac)
{
	t_lst	*stack_b;
	t_len	lenght;
	int		min;
	int		min_front;
	int		min_back;
	int		i = 0;
	int		j = 0;

	stack_b = NULL;
	get_lis(stack_a);
	j = check_lis(stack_a);
	if(!j)
		return ;
	else if(j == -1)
		return (ft_sort_rev(stack_a));
	lenght = ft_lis_controll(&stack_a, &stack_b, ac);
	j = 0;
	// while (stack_a->lenght.stack_len - 1)
	// 	push_b(&stack_b, &stack_a);
	// 	ac = 0;
	// print_stack(stack_a, stack_b);
	init_parse_it(&stack_a);
	while (stack_b)
	{
		check_places(stack_a, stack_b);
		min_front = small_parse(stack_b, 1);
		min_back = small_parse(stack_b, 0);
		if (min_front > min_back)
		{
			min_back = define_min_back(stack_b, min_back);
			i = check_place_in_a(stack_a, min_back);
			define_place(&stack_a, i, 1);
			j = stack_b_frontback(stack_b, min_back);
			if (j)
				b_front_a_back(&stack_a, &stack_b, 1);
			else
				both_back(&stack_a, &stack_b, 1);
		}
		else
		{
			min_front = define_min_front(stack_b, min_front);
			i = check_place_in_a(stack_a, min_front);
			define_place(&stack_a, i, 1);
			j = stack_b_frontback(stack_b, min_front);
			if (j)
				both_front(&stack_a, &stack_b, 1);
			else
				a_front_b_back(&stack_a, &stack_b, 1);
		}
	}
	min = small_element(stack_a);
	i = check_place_in_a(stack_a, min);
	if ((stack_a->lenght.stack_len % 2)
	&& i <= (stack_a->lenght.stack_len) / 2 + 1)
		while (stack_a->content != min)
			rotate_a(&stack_a, 1);
	else if (!(stack_a->lenght.stack_len % 2)
	&& i <= (stack_a->lenght.stack_len) / 2)
		while (stack_a->content != min)
			rotate_a(&stack_a, 1);
	else
		while (stack_a->content != min)
			reverse_a(&stack_a, 1);
			// print_stack(stack_a, stack_b);

	return ;
	while (stack_b)
	{
		j = define_small(stack_b, stack_b->content);
		i = check_place_in_a(stack_a, stack_b->content);
		define_place(&stack_a, i, 1);
		if (j && stack_a->lenght.stack_len / 2 >= i)
			both_front(&stack_a, &stack_b, 1);
		// else if (!j &&  stack_a->lenght.stack_len / 2 < i)
		// 	both_back(&stack_a, &stack_b, 1);
		else if (j && stack_a->lenght.stack_len / 2 < i)
			b_front_a_back(&stack_a, &stack_b, 1);
		// else if (!j && stack_a->lenght.stack_len / 2 >= i)
		// 	a_front_b_back(&stack_a, &stack_b, 1);
	}
	// while (stack_b)
	// {
	// 	min = small_element(stack_b);
	// 	j = define_small(stack_b, min); // return value 1 if is close to front and 0 if is close to back.
	// 	i = check_place_in_a(stack_a, min);
	// 	define_place(&stack_a, i, 1);
	// 	if (j && stack_a->lenght.stack_len / 2 >= i)
	// 		both_front(&stack_a, &stack_b, 1);
	// 	else if (!j &&  stack_a->lenght.stack_len / 2 < i)
	// 		both_back(&stack_a, &stack_b, 1);
	// 	else if (j && stack_a->lenght.stack_len / 2 < i)
	// 		b_front_a_back(&stack_a, &stack_b, 1);
	// 	else if (!j && stack_a->lenght.stack_len / 2 >= i)
	// 		a_front_b_back(&stack_a, &stack_b, 1);
	// }

	// print_stack(stack_a, stack_b);
	// print_stack(stack_a, stack_b);
}

void	ft_sort_rev(t_lst *stack_a)
{
	t_lst	*stack_b;
	int		i;
	int	 lenght;

	i = 0;
	stack_b = NULL;
	lenght = stack_a->lenght.stack_len;
	while (i++ < lenght)
	{
		push_b(&stack_b, &stack_a);
	}
	i = 0;
	while (i++ < lenght)
	{
		reverse_b(&stack_b, 1);
		push_a(&stack_a, &stack_b);
	}
}

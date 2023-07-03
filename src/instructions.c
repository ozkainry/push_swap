/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:05:12 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/07/03 13:56:36 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_pile **stack, char c)
{
	t_pile	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	push_a(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*a);
	*a = tmp;
	ft_printf("pa\n");
}

void	push_b(t_pile **a, t_pile **b)
{	
	t_pile	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*b);
	*b = tmp;
	ft_printf("pb\n");
}

void	rotate(t_pile **stack, char c)
{
	t_pile	*tmp;

	if (!*stack || !(*stack)-> next)
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	lstadd_back(stack, tmp);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	r_rotate(t_pile **stack, char c)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	*stack = lstlast(tmp);
	while (tmp2)
	{
		if (!tmp2->next->next)
		{
			tmp2->next = NULL;
			break ;
		}
		tmp2 = tmp2->next;
	}
	(*stack)->next = tmp;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

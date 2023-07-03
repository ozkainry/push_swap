/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:39:54 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/07/03 13:55:48 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*find_smallst(t_pile *stack_a)
{
	t_pile	*tmp;
	t_pile	*smlst;

	if (!stack_a)
		return (NULL);
	while (stack_a && stack_a->index != 0)
		stack_a = stack_a->next;
	smlst = stack_a;
	while (stack_a && stack_a->index != 0)
		stack_a = stack_a->next;
	tmp = stack_a;
	while (tmp)
	{
		if (smlst->content > tmp->content && tmp->index == 0)
			smlst = tmp;
		tmp = tmp->next;
	}
	return (smlst);
}

void	set_index(t_pile *stack, int argc)
{
	int		idx;
	t_pile	*tmp;

	idx = argc - 2;
	tmp = stack;
	while (idx > -1)
	{
		tmp = find_smallst(stack);
		if (!tmp)
			return ;
		tmp->index = idx;
		idx--;
	}
}

int	is_sorted(t_pile *stack)
{
	t_pile	*tmp;

	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->content > tmp->content)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

void	invert_sort_two(t_pile **stack, char c)
{
	if (is_sorted(*stack))
		swap(stack, c);
}

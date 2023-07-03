/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:34:19 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/07/03 13:57:11 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_few(t_pile **a, t_pile **b, int argc)
{
	if (argc == 3)
		sort_two(a, 'a');
	if (argc == 4)
		sort_three(a, 'a');
	if (argc == 5)
		sort_four(a, b);
	if (argc == 6)
		sort_five(a, b);
}

void	sort_two(t_pile **a, char c)
{
	if (!is_sorted(*a))
		swap(a, c);
}

void	sort_three(t_pile **a, char c)
{
	int	t[3];

	t[0] = (*a)->content;
	t[1] = (*a)->next->content;
	t[2] = (*a)->next->next->content;
	if (t[0] < t[1] && t[0] < t[2] && t[1] > t[2])
	{
		swap(a, c);
		rotate(a, c);
	}
	if (t[0] < t[1] && t[0] > t[2] && t[1] > t[2])
		r_rotate(a, c);
	if (t[0] > t[1] && t[0] < t[2] && t[1] < t[2])
		swap(a, c);
	if (t[0] > t[1] && t[0] > t[2] && t[1] > t[2])
	{
		rotate(a, c);
		swap(a, c);
	}
	if (t[0] > t[1] && t[0] > t[2] && t[1] < t[2])
		rotate(a, c);
}

void	sort_four(t_pile **a, t_pile **b)
{
	while (lstsize((*b)) != 2)
	{
		if ((*a)->index == 3 || (*a)->index == 2)
			push_b(a, b);
		else
			rotate(a, 'a');
	}
	invert_sort_two(b, 'b');
	sort_two(a, 'a');
	push_a(a, b);
	push_a(a, b);
}

void	sort_five(t_pile **a, t_pile **b)
{
	while (lstsize((*b)) != 2)
	{
		if ((*a)->index == 3 || (*a)->index == 4)
			push_b(a, b);
		else
			rotate(a, 'a');
	}
	invert_sort_two(b, 'b');
	sort_three(a, 'a');
	push_a(a, b);
	push_a(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:48:16 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/06/23 18:51:47 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	bits_len(int argc)
{
	int	len;

	len = 0;
	while (argc)
	{
		len++;
		argc /= 2;
	}
	return (len);
}

void	radix_sort(t_pile **a, t_pile **b, int argc)
{
	int	i;
	int	bits;
	int	arg;

	i = 0;
	bits = bits_len(argc);
	while (i < bits)
	{
		arg = argc - 1;
		while (arg--)
		{
			if ((*a)->index >> i & 1)
				push_b(a, b);
			else
				rotate(a, 'a');
		}
		while (lstsize(*b))
			push_a(a, b);
		i++;
	}
}

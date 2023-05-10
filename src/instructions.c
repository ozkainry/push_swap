/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:05:12 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/05/10 13:20:20 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_pile **pile)
{
	t_pile	*tmp;

	tmp = *pile;
	(*pile) = (*pile)->next;
	tmp->next = (*pile)->next;
	(*pile)->next = tmp;
}

// void	push(t_pile **pile)
// {
// 	t_pile	*tmp;

	
// }
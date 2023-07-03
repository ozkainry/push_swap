/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:09:39 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/06/23 18:59:54 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*lstnew(int content)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_pile	*lstlast(t_pile *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
}

int	lstsize(t_pile *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	lstclear(t_pile **lst)
{
	t_pile	*save;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		free(*lst);
		*lst = save;
	}
}

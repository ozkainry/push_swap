/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:36:38 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/05/09 14:09:12 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_pile
{
	int				content;
	struct s_pile	*next;
}t_pile;

t_pile	*lstnew(int content);
t_pile	*lstlast(t_pile *lst);
void	lstadd_back(t_pile **lst, t_pile *new);
int		ps_atoi(const char *str);
t_pile	*create_pile(t_pile *pile, char **argv);

int	check_arg(char **argv)

#endif
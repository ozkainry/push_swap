/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:36:35 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/07/07 15:39:25 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*create_pile(int argc, char **argv)
{
	int			arg;
	t_pile		*pile;
	t_pile		*tmp;

	arg = argc;
	pile = NULL;
	pile = lstnew(ps_atoi(*(++argv)));
	pile->index = 0;
	if (!pile)
		return (NULL);
	while (--argc > 1)
	{
		tmp = lstnew(ps_atoi(*(++argv)));
		tmp->index = 0;
		lstadd_back(&pile, tmp);
	}
	set_index(pile, arg);
	return (pile);
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		return (write(2, "Error\n", 6), 1);
	}
	if (check_all(argv))
		a = create_pile(argc, argv);
	if (!a)
		return (1);
	if (!is_sorted(a))
	{
		if (argc < 7)
			sort_few(&a, &b, argc);
		else
			radix_sort(&a, &b, argc);
	}
	lstclear(&a);
	lstclear(&b);
}

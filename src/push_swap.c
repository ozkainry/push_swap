/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:36:35 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/07/03 14:02:36 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	ps_atoi(const char *str)
{
	long int	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

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
		return (1);
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
		// while (a != NULL)
		// {
		// 	printf("%ld\t%d\n", a->content, a->index);
		// 	a = a->next;
		// }
	}
	lstclear(&a);
	lstclear(&b);
}

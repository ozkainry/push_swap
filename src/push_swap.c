/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:36:35 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/05/10 16:38:06 by ozozdemi         ###   ########.fr       */
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

t_pile	*create_pile(t_pile *pile, char **argv)
{
	int		i;
	t_pile	*tmp;

	i = 1;
	pile = lstnew(ps_atoi(argv[i]));
	i++;
	while (argv[i])
	{
		tmp = lstnew(ps_atoi(argv[i]));
		lstadd_back(&pile, tmp);
		i++;
	}
	return (pile);
}

long int	find_zero(t_pile *pile)
{
	while (pile->index != 0)
	{
		pile = pile->next;
	}
	return (pile->content);
}

void	index_nb(t_pile	*pile)
{
	int		i;
	int		j;
	int		k;
	int		size;
	t_pile	*tmp2;
	t_pile	*tmp;

	size = lstsize(pile);
	i = 0;
	j = 1;
	tmp2 = pile;
	tmp = pile;
	while (i < size)
	{
		k = find_zero(pile);
		while (pile != NULL)
		{
			if (pile->index == 0 && pile->content <= k)
			{
				tmp2 = pile;
				k = pile->content;
			}
			pile = pile->next;
		}
		tmp2->index = j;
		pile = tmp;
		j++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_pile	*a;

	a = NULL;
	if (argc > 1)
	{
		if (check_all(argv))
			a = create_pile(a, argv);
		// swap(&a);
		index_nb(a);
		while (a != NULL)
		{
			printf("%ld        %d\n", a->content, a->index);
			a = a->next;
		}
	}
	free(a);
	return (0);
}

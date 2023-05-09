/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:36:35 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/05/09 13:36:23 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

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
	while (argv[i] != NULL)
	{
		tmp = lstnew(ps_atoi(argv[i]));
		lstadd_back(&pile, tmp);
		i++;
	}
	return (pile);
}

int	main(int argc, char **argv)
{
	t_pile	*a;

	(void)	argc;
	a = NULL;
	
	a = create_pile(a, argv);
	while (a != NULL)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:47:13 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/06/23 14:41:46 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ps_atoi(argv[i]) == ps_atoi(argv[j]))
			{	
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_nb(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ps_atoi(argv[i]) < -2147483648 || ps_atoi(argv[i]) > 2147483647)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_all(char **argv)
{
	if (!check_nb(argv) || !check_double(argv) || !check_int(argv))
		return (0);
	return (1);
}

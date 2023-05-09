/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:47:13 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/05/09 14:09:07 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	check_double(char **argv)
// {
	
// }

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] >= '9') || argv[i][j] >= '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

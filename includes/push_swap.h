/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozozdemi <ozozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:36:38 by ozozdemi          #+#    #+#             */
/*   Updated: 2023/07/03 13:56:41 by ozozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_pile
{
	long int		content;
	int				index;
	struct s_pile	*next;
}	t_pile;

t_pile		*lstnew(int content);
t_pile		*lstlast(t_pile *lst);
void		lstadd_back(t_pile **lst, t_pile *new);
void		lstadd_back_ps(t_pile **lst, t_pile *new);
int			lstsize(t_pile *lst);
void		lstclear(t_pile **lst);
void		add_to_stack(t_pile **stack, int nb);

long int	ps_atoi(const char *str);

int			check_double(char **argv);
int			check_nb(char **argv);
int			check_int(char **argv);
int			check_all(char **argv);
t_pile		*create_pile(int argc, char **argv);

t_pile		*find_smallst(t_pile *stack_a);
void		set_index(t_pile *stack, int argc);
int			is_sorted(t_pile *stack);
void		invert_sort_two(t_pile **stack, char c);

void		swap(t_pile **stack, char c);
void		push_a(t_pile **a, t_pile **b);
void		push_b(t_pile **a, t_pile **b);
void		rotate(t_pile **stack, char c);
void		r_rotate(t_pile **stack, char c);

void		sort_few(t_pile **a, t_pile **b, int argc);
void		sort_two(t_pile **a, char c);
void		sort_three(t_pile **a, char c);
void		sort_four(t_pile **a, t_pile **b);
void		sort_five(t_pile **a, t_pile **b);

int			bits_len(int argc);
void		radix_sort(t_pile **a, t_pile **b, int argc);

#endif
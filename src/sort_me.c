/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 00:44:50 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/07 00:44:52 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_to_a(t_swap **pile)
{
	while (stack_size(pile[1]) > 0)
		push(&pile, 0);
}

void		sort_me(t_swap **pile)
{
	int		size;
	int		low;

	size = stack_size(pile[0]);
	while (stack_size(pile[1]) != size)
	{
		low = lowest_nb(pile[0]);
		if (is_sorted(pile, 0) && is_sorted(pile, 1))
			break ;
		else if (low == 0)
			push(&pile, 1);
		else if (low == 1)
			swap(&pile, 0);
		else if (low <= stack_size(pile[0]) / 2)
			rotate(&pile, 0);
		else if (low > stack_size(pile[0]) / 2)
			reverse(&pile, 0);
	}
	b_to_a(pile);
	ft_putendl("");
}

void		pre_sort(t_swap **pile)
{
	reverse(&pile, 0);
	reverse(&pile, 0);
	swap(&pile, 0);
	rotate(&pile, 0);
	rotate(&pile, 0);
	if (!is_sorted(pile, 0))
		sort_me(pile);
	ft_putendl("");
	exit(0);
}

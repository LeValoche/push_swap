/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 00:44:57 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/07 00:45:00 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_swap ***pile, int ch)
{
	t_swap	*a;
	t_swap	*b;

	a = *pile[ch];
	b = a->next;
	a->next = b->next;
	b->next = a;
	*pile[ch] = b;
	if (ch == 0)
		ft_putstr("sa ");
	else
		ft_putstr("sb ");
}

void		rotate(t_swap ***pile, int ch)
{
	t_swap	*a;
	t_swap	*b;

	a = *pile[ch];
	b = a;
	while (b->next != NULL)
		b = b->next;
	a = a->next;
	b->next = *pile[ch];
	b->next->next = NULL;
	*pile[ch] = a;
	if (ch == 0)
		ft_putstr("ra ");
	else
		ft_putstr("rb ");
}

void		reverse(t_swap ***pile, int ch)
{
	t_swap	*a;
	t_swap	*b;

	b = *pile[ch];
	if (b->next->next == NULL)
		return (swap(pile, ch));
	while (b->next->next != NULL)
		b = b->next;
	b->next->next = *pile[ch];
	a = b->next;
	b->next = NULL;
	*pile[ch] = a;
	if (ch == 0)
		ft_putstr("rra ");
	else
		ft_putstr("rrb ");
}

void		push(t_swap ***pile, int ch)
{
	t_swap	**stack;

	stack = *pile;
	stack[ch] = push_list(stack[ch], stack[(ch + 1) % 2]->n);
	stack[(ch + 1) % 2] = stack[(ch + 1) % 2]->next;
	if (ch == 0)
		ft_putstr("pa ");
	else
		ft_putstr("pb ");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 00:45:04 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/07 00:45:05 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			put_tiret(int n)
{
	int			i;

	i = -1;
	while (++i < n)
		ft_putchar('-');
	ft_putendl("");
}

void			put_space(int n)
{
	while (n-- >= 0)
		ft_putchar(' ');
}

int				biggest_len(t_swap **pile)
{
	t_swap		*a;
	t_swap		*b;
	int			res;

	a = A;
	b = B;
	res = 0;
	while (a != NULL)
	{
		if (ft_intlen(a->n) > res)
			res = ft_intlen(a->n);
		a = a->next;
	}
	while (b != NULL)
	{
		if (ft_intlen(b->n) > res)
			res = ft_intlen(b->n);
		b = b->next;
	}
	return (res);
}

void			put_lol(t_swap *a, t_swap *b, int len)
{
	ft_putstr("| ");
	if (a != NULL)
	{
		ft_putnbr(a->n);
		if (ft_intlen(a->n) < len)
			put_space(len - ft_intlen(a->n) - 1);
	}
	else
		put_space(len - 1);
	ft_putstr(" | ");
	if (b != NULL)
	{
		if (ft_intlen(b->n) < len)
			put_space(len - ft_intlen(b->n) - 1);
		ft_putnbr(b->n);
	}
	else
		put_space(len - 1);
	ft_putendl(" |");
}

void			print_stacks(t_swap **pile)
{
	t_swap		*a;
	t_swap		*b;
	static int	size;
	static int	len;
	int			i;

	CLEAR;
	a = A;
	b = B;
	i = -1;
	if (!size)
		size = stack_size(pile[0]);
	if (!len)
		len = biggest_len(pile);
	put_tiret(len * 2 + 7);
	while (++i < size)
	{
		put_lol(a, b, len);
		put_tiret(len * 2 + 7);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_putendl("");
}

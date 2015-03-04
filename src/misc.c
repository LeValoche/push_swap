/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 00:44:45 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/07 00:44:47 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_puterror(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int				ft_strisdigit(char *str)
{
	int			i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int				re_sorted(t_swap **pile, int ch)
{
	t_swap		*tmp;

	tmp = pile[ch];
	while (tmp && tmp->next)
	{
		if (tmp->next && ch == 0 && tmp->n < tmp->next->n)
			return (0);
		if (tmp->next && ch == 1 && tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				fck_sorted(t_swap **pile, int ch)
{
	t_swap		*tmp;

	tmp = pile[ch];
	while (tmp && tmp->next && tmp->next->next)
	{
		if (tmp->next && ch == 0 && tmp->n > tmp->next->n)
			return (0);
		if (tmp->next && ch == 1 && tmp->n < tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void			treat_easy_sort(t_swap **pile)
{
	t_swap		*save;

	save = pile[0];
	if (re_sorted(pile, 0))
	{
		rotate(&pile, 0);
		swap(&pile, 0);
		ft_putendl("");
		exit(0);
	}
	pile[0] = pile[0]->next;
	if (is_sorted(pile, 0))
	{
		pile[0] = save;
		rotate(&pile, 0);
		ft_putendl("");
		exit(0);
	}
	else
		pile[0] = save;
}

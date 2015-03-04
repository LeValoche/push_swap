/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 00:44:37 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/07 00:44:39 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				lowest_nb(t_swap *pile)
{
	int			i;
	int			save;
	int			value;
	t_swap		*tmp;

	i = 0;
	save = 0;
	tmp = pile;
	value = tmp->n;
	while (tmp != NULL)
	{
		if (tmp->n < value)
		{
			value = tmp->n;
			save = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (save);
}

int				stack_size(t_swap *pile)
{
	int			i;
	t_swap		*tmp;

	i = 0;
	tmp = pile;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int				is_sorted(t_swap **pile, int ch)
{
	t_swap		*tmp;

	tmp = pile[ch];
	while (tmp && tmp->next)
	{
		if (tmp->next && ch == 0 && tmp->n > tmp->next->n)
			return (0);
		if (tmp->next && ch == 1 && tmp->n < tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_swap			*push_list(t_swap *list, int nb)
{
	t_swap		*nw;

	if (!(nw = (t_swap *)malloc(sizeof(t_swap))))
		ft_puterror();
	nw->n = nb;
	nw->next = NULL;
	if (!list)
		return (nw);
	nw->next = list;
	return (nw);
}

t_swap			*push_end_list(t_swap *list, int nb)
{
	t_swap		*nw;
	t_swap		*tmp;

	if (!(nw = (t_swap *)malloc(sizeof(t_swap))))
		ft_puterror();
	nw->n = nb;
	nw->next = NULL;
	if (!list)
		return (nw);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = nw;
	return (list);
}

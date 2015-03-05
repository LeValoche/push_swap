/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 00:44:41 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/07 00:44:42 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_list(t_swap *list, int nb)
{
	t_swap	*browser;

	browser = list;
	while (browser != NULL)
	{
		if (browser->n == nb)
			ft_puterror();
		browser = browser->next;
	}
}

t_swap		*check_entry(char **av)
{
	int		i;
	t_swap	*a;

	i = -1;
	a = NULL;
	while (av[++i])
	{
		if (!ft_strisdigit(av[i]))
			ft_puterror();
		if (ft_strlen(av[i]) != (unsigned int)ft_intlen(ft_atoi(av[i])))
			ft_puterror();
		check_list(a, ft_atoi(av[i]));
		a = push_end_list(a, ft_atoi(av[i]));
	}
	return (a);
}

int			main(int ac, char **av)
{
	t_swap	**pile;

	pile = (t_swap **)malloc(sizeof(t_swap *) * 2);
	if (ac <= 1)
		ft_puterror();
	av++;
	A = check_entry(av);
	B = NULL;
	if (stack_size(A) == 3 && !is_sorted(pile, 0))
		treat_easy_sort(pile);
	else if (fck_sorted(pile, 0) && !is_sorted(pile, 0) && stack_size(A) > 3)
		pre_sort(pile);
	sort_me(pile);
	free(pile);
	return (0);
}

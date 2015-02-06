#include "push_swap.h"

int			lowest_nb(t_swap *pile)
{
	int		i;
	int		save;
	int		value;
	t_swap	*tmp;

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

int			stack_size(t_swap *pile)
{
	int		i;
	t_swap	*tmp;

	i = 0;
	tmp = pile;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			is_sorted(t_swap **pile, int ch)
{
	t_swap	*tmp;

	tmp = pile[ch];
	while (tmp->next != NULL)
	{
		if (ch == 0 && tmp->n > tmp->next->n)
			return (0);
		if (ch == 1 && tmp->n < tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

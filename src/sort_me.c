#include "push_swap.h"

static void	print_piles(t_swap **pile)
{
	t_swap	*a;
	t_swap	*b;

	a = A;
	b = B;
	while (a != NULL)
	{
		ft_putnbr(a->n);
		ft_putstr(" ");
		a = a->next;
	}
	ft_putendl("");
	while (b != NULL)
	{
		ft_putnbr(b->n);
		ft_putstr(" ");
		b = b->next;
	}
	ft_putendl("\n");
}

static void	treat_options(t_swap **pile, int options, char *res)
{
	if (options & 0b010)
	{
		system("clear");
		print_stacks(pile);
		ft_putendl(ft_strtrim(res));
		sleep(1);
	}
	else if (options & 0b001)
	{
		print_piles(pile);
	}
	else if (is_sorted(pile, 0) && pile[1] == NULL)
		ft_putendl(ft_strtrim(res));
}

static char	*b_to_a(t_swap **pile, int options, char *res)
{
	while (stack_size(pile[1]) > 0)
	{
		res = ft_strjoin(res, push(&pile, 0));
		treat_options(pile, options, res);
	}
	return (res);
}

void		sort_me(t_swap **pile, int options)
{
	int		i;
	int		size;
	int		low;
	char	*res;

	i = 0;
	size = stack_size(pile[0]);
	res = ft_strdup("");
	while (stack_size(pile[1]) != size)
	{
		treat_options(pile, options, res);
		low = lowest_nb(pile[0]);
		if (is_sorted(pile, 0) && is_sorted(pile, 1))
			break;
		else if (low == 0)
			res = ft_strjoin(res, push(&pile, 1));
		else if (low == 1)
			res = ft_strjoin(res, swap(&pile, 0));
		else if (low < stack_size(pile[0]) / 2)
			res = ft_strjoin(res, rotate(&pile, 0));
		else if (low >= stack_size(pile[0]) / 2)
			res = ft_strjoin(res, reverse(&pile, 0));
	}
	res = ft_strjoin(res, b_to_a(pile, options, res));
}

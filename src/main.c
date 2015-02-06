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
		check_list(a, ft_atoi(av[i]));
		a = push_list(a, ft_atoi(av[i]));
	}
	return (a);
}

int			ft_options(char *str)
{
	int		options;

	options = 0b000;
	str++;
	while (*str)
	{
		if (*str == 'v')
			options = options | 0b001;
		else if (*str == 'l')
			options = options | 0b010;
		str++;
	}
	return (options);
}

int			main(int ac, char **av)
{
	t_swap	**pile;
	int		options;

	pile = (t_swap **)malloc(sizeof(t_swap *) * 2);
	options = 0;
	if (ac <= 1)
		ft_puterror();
	av++;
	while (av[0][0] == '-')
	{
		options = options | ft_options(av[0]);
		av++;
	}
	A = check_entry(av);
	B = NULL;
	sort_me(pile, options);
	return (0);
}
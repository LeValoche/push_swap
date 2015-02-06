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
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
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

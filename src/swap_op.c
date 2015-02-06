#include "push_swap.h"

char		*swap(t_swap ***pile, int ch)
{
	t_swap	*a;
	t_swap	*b;

	a = *pile[ch];
	b = a->next;
	a->next = b->next;
	b->next = a;
	*pile[ch] = b;
	return (ft_strjoin(" s", (ch == 0) ? "a" : "b"));
}

char		*rotate(t_swap ***pile, int ch)
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
	return (ft_strjoin(" r", (ch == 0) ? "a" : "b"));
}

char		*reverse(t_swap ***pile, int ch)
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
	return (ft_strjoin(" rr", (ch == 0) ? "a" : "b"));
}

char		*push(t_swap ***pile, int ch)
{
	t_swap	**stack;

	stack = *pile;
	stack[ch] = push_list(stack[ch], stack[(ch + 1) % 2]->n);
	stack[(ch + 1) % 2] = stack[(ch + 1) % 2]->next;
	return (ft_strjoin(" p", (ch == 0) ? "a" : "b"));
}

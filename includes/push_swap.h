/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 00:46:57 by vcohere           #+#    #+#             */
/*   Updated: 2015/02/07 00:46:59 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# define A pile[0]
# define B pile[1]
# define CLEAR ft_putstr("\033[2J\033[1;1H")

typedef struct		s_swap
{
	int				n;
	struct s_swap	*next;
}					t_swap;

void				ft_puterror(void);
t_swap				*push_list(t_swap *list, int nb);
t_swap				*push_end_list(t_swap *list, int nb);
void				check_list(t_swap *list, int nb);
int					ft_strisdigit(char *str);
void				swap(t_swap ***pile, int ch);
void				rotate(t_swap ***pile, int ch);
void				reverse(t_swap ***pile, int ch);
void				push(t_swap ***pile, int ch);
void				sort_me(t_swap **pile);
int					is_sorted(t_swap **pile, int ch);
int					lowest_nb(t_swap *pile);
int					stack_size(t_swap *pile);
int					re_sorted(t_swap **pile, int ch);
void				treat_options(t_swap **pile);
int					fck_sorted(t_swap **pile, int ch);
void				treat_easy_sort(t_swap **pile);
void				pre_sort(t_swap **pile);

#endif

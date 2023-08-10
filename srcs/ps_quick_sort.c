/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:27:05 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 20:03:12 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_is_sorted(t_list *pile, int indicator, int len)
{
	int	i;
	int	j;

	while (--len)
	{
		i = *(int *)(pile->content);
		j = *(int *)(pile->next->content);
		if (indicator == 0 && i > j)
			return (1);
		else if (indicator == 1 && i < j)
			return (1);
		pile = pile->next;
	}
	return (0);
}

void	ps_quick_sort_pile_b(t_list *pile_a, t_list *pile_b, int len, \
		t_list **output)
{
	if (!ps_is_sorted(pile_b, 1, len))
	{
		while (len--)
			ps_p_instructions("pa", &pile_a, &pile_b, output);
		return ;
	}
	if (len < 4)
		return (ps_simple_sort_pile_b(pile_a, pile_b, len, output));
	ps_descending_pile_b(&pile_a, &pile_b, len, output);
	ps_quick_sort_pile_a(pile_a, pile_b, len / 2 + len % 2, output);
	ps_quick_sort_pile_b(pile_a, pile_b, len / 2, output);
}

void	ps_quick_sort_pile_a(t_list *pile_a, t_list *pile_b, int len, \
		t_list **output)
{
	if (!ps_is_sorted(pile_a, 0, len))
		return ;
	if (len < 4)
		return (ps_simple_sort_pile_a(pile_a, pile_b, len, output));
	ps_descending_pile_a(&pile_a, &pile_b, len, output);
	ps_quick_sort_pile_a(pile_a, pile_b, len / 2 + len % 2, output);
	ps_quick_sort_pile_b(pile_a, pile_b, len / 2, output);
}

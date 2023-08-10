/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimise_quick_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:22:10 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 16:30:22 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_get_median(t_list *pile, int len)
{
	int	*list;
	int	j;
	int	i;

	list = (int *)malloc(sizeof(int) * len);
	if (list == NULL)
		ps_error();
	i = -1;
	while (++i < len)
	{
		list[i] = *(int *)(pile->content);
		pile = pile->next;
	}
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			if (list[j] > list[i])
				ft_swap(&list[j], &list[i]);
	}
	i = list[len / 2];
	free(list);
	return (i);
}

void	ps_descending_pile_b(t_list **pile_a, t_list **pile_b, int len, \
		t_list **output)
{
	int	median;
	int	pushed;
	int	pushed_under;

	pushed = len;
	pushed_under = 0;
	median = ps_get_median(*pile_b, len);
	while (pushed != (len / 2))
	{
		if (*(int *)((*pile_b)->content) >= median)
		{		
			pushed--;
			ps_p_instructions("pa", pile_a, pile_b, output);
		}
		else
		{
			pushed_under++;
			ps_r_instructions("rb", pile_a, pile_b, output);
		}
	}
	if (len / 2 != ft_lstsize(*pile_b))
		while (pushed_under--)
			ps_rr_instructions("rrb", pile_a, pile_b, output);
}

void	ps_descending_pile_a(t_list **pile_a, t_list **pile_b, int len, \
		t_list **output)
{
	int	median;
	int	pushed;
	int	pushed_under;

	pushed = len;
	pushed_under = 0;
	median = ps_get_median(*pile_a, len);
	while (pushed != (len / 2 + len % 2))
	{
		if (*(int *)((*pile_a)->content) < median)
		{		
			pushed--;
			ps_p_instructions("pb", pile_a, pile_b, output);
		}
		else
		{
			pushed_under++;
			ps_r_instructions("ra", pile_a, pile_b, output);
		}
	}
	if ((len / 2 + len % 2) != ft_lstsize(*pile_a))
		while (pushed_under--)
			ps_rr_instructions("rra", pile_a, pile_b, output);
}

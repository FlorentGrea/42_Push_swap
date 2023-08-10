/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:27:44 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 21:05:48 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	*ps_get_first_values(t_list *pile)
{
	int	*v;

	v = (int *)malloc(sizeof(int) * 3);
	if (v == NULL)
		ps_error();
	if (pile)
		v[0] = *(int *)(pile->content);
	if (pile->next)
		v[1] = *(int *)(pile->next->content);
	if (pile->next && pile->next->next)
		v[2] = *(int *)(pile->next->next->content);
	return (v);
}

void	ps_simple_sort_pile_b(t_list *pile_a, t_list *pile_b, int len, \
		t_list **output)
{
	int	mv_count;
	int	*v;

	mv_count = len;
	v = ps_get_first_values(pile_b);
	if (len > 1 && v[0] < v[1])
		ps_s_instructions("sb", &pile_a, &pile_b, output);
	while (mv_count--)
	{
		ps_p_instructions("pa", &pile_a, &pile_b, output);
		if (len == 3 && mv_count == 2 && !(v[0] < v[1] && v[0] > v[2]))
			ps_s_instructions("sb", &pile_a, &pile_b, output);
		if (len == 3 && mv_count == 1 && v[0] < v[2] && v[1] < v[2])
			ps_s_instructions("sa", &pile_a, &pile_b, output);
	}
	free(v);
}

void	ps_simple_sort_pile_a(t_list *pile_a, t_list *pile_b, int len, \
		t_list **output)
{
	int	*v;

	v = ps_get_first_values(pile_a);
	if (v[0] > v[1])
		ps_s_instructions("sa", &pile_a, &pile_b, output);
	if (len == 3 && !(v[0] > v[1] && v[0] < v[2]))
	{
		ps_r_instructions("ra", &pile_a, &pile_b, output);
		ps_s_instructions("sa", &pile_a, &pile_b, output);
		ps_rr_instructions("rra", &pile_a, &pile_b, output);
	}
	if (len == 3 && v[0] > v[2] && v[1] > v[2])
		ps_s_instructions("sa", &pile_a, &pile_b, output);
	free(v);
}

void	ps_simple_sort(t_list *pile_a, t_list *pile_b, t_list **output)
{
	int	*v;

	v = ps_get_first_values(pile_a);
	if (v[0] > v[1] && v[0] > v[2] && v[1] > v[2])
		ps_s_instructions("sa", &pile_a, &pile_b, output);
	if (v[0] > v[1] && v[0] > v[2] && v[1] < v[2])
		ps_r_instructions("ra", &pile_a, &pile_b, output);
	if (v[0] > v[2] && v[1] > v[2])
		ps_rr_instructions("rra", &pile_a, &pile_b, output);
}

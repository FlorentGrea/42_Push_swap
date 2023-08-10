/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimise_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:26:10 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 20:35:23 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_modify_output(t_list **output)
{
	t_list	*tmp;

	tmp = (*output)->next;
	(*output)->next = (*output)->next->next;
	free(tmp->content);
	free(tmp);
}

void	ps_optimise_output(t_list **output)
{
	char	*s1;
	char	*s2;
	t_list	*tmp;

	tmp = *output;
	while (tmp->next)
	{
		s1 = tmp->content;
		s2 = tmp->next->content;
		if ((!ft_strncmp("sa", s1, 2) && !ft_strncmp("sb", s2, 2)) || \
			(!ft_strncmp("sb", s1, 2) && !ft_strncmp("sa", s2, 2)))
			ft_memcpy(tmp->content, "ss", 2);
		if ((!ft_strncmp("ra", s1, 2) && !ft_strncmp("rb", s2, 2)) || \
			(!ft_strncmp("rb", s1, 2) && !ft_strncmp("ra", s2, 2)))
			ft_memcpy(tmp->content, "rr", 2);
		if ((!ft_strncmp("rra", s1, 3) && !ft_strncmp("rrb", s2, 3)) || \
			(!ft_strncmp("rrb", s1, 3) && !ft_strncmp("rra", s2, 3)))
			ft_memcpy(tmp->content, "rrr", 3);
		if (!ft_strncmp("ss", tmp->content, 2) || \
				(!ft_strncmp("rr", tmp->content, 2) && \
				ft_strlen(tmp->content) == 2) || \
				!ft_strncmp("rrr", tmp->content, 3))
			ps_modify_output(&tmp);
		tmp = tmp->next;
	}
}

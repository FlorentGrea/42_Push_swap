/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:25:29 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 20:19:30 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 *	"s" instructions swap the first 2 element of a pile.
 *
 *	If the instruction is not "sa" (so either "sb" or "ss"),
 *	then we enter in the second condition.
 *	If the instruction is not "sb" (so either "sa" or "ss"),
 *	then we enter in the third condition.
 */

void	ps_s_instructions(char *instr, t_list **pile_a, t_list **pile_b, \
		t_list **output)
{
	t_list	*tmp;

	ft_lstadd_back(output, ft_lstnew(ft_strdup(instr)));
	if (!ft_strncmp(instr, "ss", 2))
	{
		if (!*pile_a || !*pile_b)
			return ;
		if (!(*pile_a)->next || !(*pile_b)->next)
			return ;
	}
	if (ft_strncmp(instr, "sa", 2) && *pile_b && (*pile_b)->next)
	{
		tmp = (*pile_b)->next;
		(*pile_b)->next = tmp->next;
		tmp->next = *pile_b;
		*pile_b = tmp;
	}
	if (ft_strncmp(instr, "sb", 2) && *pile_a && (*pile_a)->next)
	{
		tmp = (*pile_a)->next;
		(*pile_a)->next = tmp->next;
		tmp->next = *pile_a;
		*pile_a = tmp;
	}
}

/*
 *	"p" instructions push the first element of a pile to the top of the next one.
 *
 *	If the instruction is "pa",
 *	then we enter in the first condition.
 *	If the instruction is "pb",
 *	then we enter in the second condition.
 */

void	ps_p_instructions(char *instr, t_list **pile_a, t_list **pile_b, \
		t_list **output)
{
	t_list	*tmp;

	ft_lstadd_back(output, ft_lstnew(ft_strdup(instr)));
	if (!ft_strncmp(instr, "pa", 2) && *pile_b)
	{
		tmp = (*pile_b)->next;
		(*pile_b)->next = *pile_a;
		*pile_a = *pile_b;
		*pile_b = tmp;
	}
	if (!ft_strncmp(instr, "pb", 2) && *pile_a)
	{
		tmp = (*pile_a)->next;
		(*pile_a)->next = *pile_b;
		*pile_b = *pile_a;
		*pile_a = tmp;
	}
}

/*
 *	"r" instructions take the first element and make it the last one.
 *
 *	If the instruction is not "ra" (so either "rb" or "rr"),
 *	then we enter in the first condition.
 *	If the instruction is not "rb" (so either "ra" or "rr"),
 *	then we enter in the second condition.
 */

void	ps_r_instructions(char *instr, t_list **pile_a, t_list **pile_b, \
		t_list **output)
{
	t_list	*tmp;

	ft_lstadd_back(output, ft_lstnew(ft_strdup(instr)));
	if (ft_strncmp(instr, "ra", 2))
	{
		tmp = (*pile_b)->next;
		(*pile_b)->next = NULL;
		ft_lstadd_back(&tmp, *pile_b);
		*pile_b = tmp;
	}
	if (ft_strncmp(instr, "rb", 2))
	{
		tmp = (*pile_a)->next;
		(*pile_a)->next = NULL;
		ft_lstadd_back(&tmp, *pile_a);
		*pile_a = tmp;
	}
}

/*
 *	"rr" instructions take the last element and make it the first one.
 *
 *	If the instruction is not "rra" (so either "rrb" or "rrr"),
 *	then we enter in the first condition.
 *	If the instruction is not "rrb" (so either "rra" or "rrr"),
 *	then we enter in the second condition.
 */

void	ps_rr_instructions(char *instr, t_list **pile_a, t_list **pile_b, \
		t_list **output)
{
	t_list	*tmp;

	ft_lstadd_back(output, ft_lstnew(ft_strdup(instr)));
	if (ft_strncmp(instr, "rra", 3))
	{
		tmp = *pile_b;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(pile_b, ft_lstlast(*pile_b));
		tmp->next = NULL;
	}
	if (ft_strncmp(instr, "rrb", 3))
	{
		tmp = *pile_a;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(pile_a, ft_lstlast(*pile_a));
		tmp->next = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:28:32 by fgrea             #+#    #+#             */
/*   Updated: 2021/11/09 20:40:28 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_error(void)
{
	if (errno == 0)
		ft_putstr_fd("Wrong arguments\n", 1);
	else
		perror(strerror(errno));
	exit(0);
}

int	*ps_check_value(char *av)
{
	int		i;
	int		*ret;
	char	*verif;

	if (*av == '+' || *av == '-')
		if (!*(av + 1))
			ps_error();
	i = (*av == '+' || *av == '-');
	while (av[i] && av[i] != ' ')
		if (!ft_isdigit(av[i++]))
			ps_error();
	ret = (int *)malloc(sizeof(int));
	if (ret == NULL)
		ps_error();
	*ret = ft_atoi(av);
	verif = ft_itoa(*ret);
	if (verif == NULL)
		ps_error();
	if (*av == '+')
		av++;
	if (ft_strncmp(av, verif, ft_strlen(verif)))
		ps_error();
	free(verif);
	return (ret);
}

void	ps_check_duplicate(t_list *pile)
{
	t_list	*tmp;
	int		value;

	while (pile)
	{
		value = *(int *)(pile->content);
		tmp = pile->next;
		while (tmp)
		{
			if (value == *(int *)(tmp->content))
				ps_error();
			tmp = tmp->next;
		}
		pile = pile->next;
	}
}

t_list	*ps_create_pile(char **av)
{
	t_list	*pile_a;
	int		*ret;

	pile_a = NULL;
	while (*av)
	{
		ret = ps_check_value(*av);
		ft_lstadd_back(&pile_a, ft_lstnew(ret));
		ps_check_duplicate(pile_a);
		*av = ft_strchr(*av, ' ');
		if (*av != NULL)
			(*av)++;
		else
			av++;
	}
	return (pile_a);
}

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*output;

	if (ac < 2)
		ps_error();
	pile_a = ps_create_pile(++av);
	output = NULL;
	if (ft_lstsize(pile_a) == 3)
		ps_simple_sort(pile_a, NULL, &output);
	ps_quick_sort_pile_a(pile_a, NULL, ft_lstsize(pile_a), &output);
	if (output)
		ps_optimise_output(&output);
	while (output)
	{
		ft_putstr_fd(output->content, 1);
		ft_putstr_fd("\n", 1);
		output = output->next;
	}
	exit(0);
	return (0);
}

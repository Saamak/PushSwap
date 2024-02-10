/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:29:16 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/10 01:40:20 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_only_num(char **char_av, t_data *data)
{
	int	j;
	int i;

	j = 0;
	i = 0;
	while (char_av[i])
	{
		while(char_av[i][j])
		{
			if (!((char_av[i][j] >= '0' && char_av[i][j] <= '9')
				|| char_av[i][j] == ' '
				|| char_av[i][j] == '+' || char_av[i][j] == '-'))
				{
					if(data->i_bool == 1)
						args_error1(char_av, data);
					else
						simple_error(data);
				}
			j++;
		}
		i++;
		j = 0;
	}
}

char	**is_one_arg(int ac, char **av, t_data *data)
{
	if (ac == 2)
	{
		data->i_bool = 1;
		av = ft_split(av[1] , ' ');
		check_only_num(av, data);
	}
	else
	{
		av ++;
		check_only_num(av, data);
	}
	check_nobody_else(av, data);
	return (av);
}

int	check_double(t_list **a)
{
	t_list *current;
	t_list *nbr;

	current = *a;
	nbr =	*a;
	current = current->next;
	while (nbr != NULL)
	{
		if (current != NULL)
		{
			if (nbr->content == current->content)
				return (1);
			current = current->next;
			if (nbr == current)
				current = current->next;
		}
		else
		{
			nbr = nbr->next;
			current = *a;
		}
	}
	return (0);
}

void	check_nobody_else(char **av, t_data *data)
{
	int i;

	i = 0;
	if (av[i + 1] == NULL)
	{
		if (data->i_bool == 0)
			simple_error(data);
		else
			args_error1(av, data);
	}
}

void	stack_a_isSorted(char **tab, t_data *data, t_list **a)
{
	t_list *current;
	int	greater;

	greater = 0;
	current = *a;
	while(current->next != NULL)
	{
		if (current->content > current->next->content)
		{
			greater = 1;
		}
		current = current->next;
	}
	if (greater == 0)
		double_error(tab, data, *a);
}

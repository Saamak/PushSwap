/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:52:45 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/13 22:27:05 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_data	*data;
	t_list	*b;
	char	**list;

	a = NULL;
	b = NULL;
	data = NULL;
	data = data_s_init(data);
	if (ac == 1)
		simple_error(data);
	check_null(av, data);
	check_empty(av, data);
	list = create_av(ac, av, data);
	check_only_num(list, data);
	first_put_lst(&a, list, data);
	if (check_double(&a))
		double_error(list, data, &a);
	stack_a_is_sorted(list, data, &a);
	find_index(&a);
	if (data->argv_count <= 5)
		simple_sort_hub(&a, &b, data, list);
	ft_sort_big_list(&a, &b);
	success(list, data, &a, &b);
	return (0);
}

t_data	*data_s_init(t_data *data)
{
	data = malloc(sizeof(t_data));
	data->argv_count = 0;
	data->index = 0;
	return (data);
}

void	stack_a_is_sorted(char **tab, t_data *data, t_list **a)
{
	t_list	*current;
	int		greater;

	greater = 0;
	current = *a;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			greater = 1;
		current = current->next;
	}
	if (greater == 0)
		already_sorted(tab, data, a);
}

void	check_empty(char **av, t_data *data)
{
	int	i;
	int	j;
	int	nb ;

	nb = 0;
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (av[i][j] == '\0')
				args_error1(data);
			else
			{
				nb = 1;
				break ;
			}
		}
		i++;
	}
	if (nb == 0)
		args_error1(data);
}

void	check_null(char **av, t_data *data)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			args_error1(data);
		i++;
	}
}

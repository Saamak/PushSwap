/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:52:45 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/11 20:50:55 by ppitzini         ###   ########.fr       */
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
	list = create_av(ac, av, data);
	check_sign(list, data);
	first_put_lst(&a, list, data);
	stack_a_is_sorted(list, data, &a);
	if (check_double(&a))
		double_error(list, data, &a);
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

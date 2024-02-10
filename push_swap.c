/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:52:45 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/10 20:03:16 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a = NULL;
	t_data	*data = NULL;
	t_list	*b = NULL;

	data = data_s_init(data);
	if (ac == 1)
		simple_error(data);
	av = is_one_arg(ac, av, data);
	argv_counter(av, data);
	check_sign(av, data);
	first_put_lst(&a, av, data);
	stack_a_is_sorted(av, data, &a);
	if (check_double(&a))
	{
		double_error(av, data, a);
	}
	find_index(&a, data);
	printf("A\n");
	display(&a);
	printf("B\n");
	display(&b);
	free(data);
	free_list(a);
	free_list(b);
	return (0);
}

t_data	*data_s_init(t_data *data)
{
	data = malloc(sizeof(t_data));
	data->i_bool = 0;
	data->argv_count = 0;
	data->index = 0;
	return (data);
}

void	display(t_list **a)
{
	t_list	*current;

	current = *a;
	while (current != NULL)
	{
		printf("-- %d   index : ", current->content);
		printf(" %d\n", current->index);
		current = current->next;
	}
}

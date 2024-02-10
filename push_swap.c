/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:52:45 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/10 01:50:45 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a = NULL;
	t_data	*data;
	t_list	*b = NULL;

	data = malloc(sizeof(t_data));
	data->i_bool = 0;
	data->argv_count = 0;
	if (ac == 1)
		simple_error(data);
	av = is_one_arg(ac, av, data);
	argv_counter(av, data);
	check_sign(av, data);
	first_put_lst(&a, av);
	stack_a_isSorted(av, data, &a);
	if (check_double(&a))
	{
		double_error(av, data, a);
	}
	push_b(&a, &b);
	printf("A\n");
	display(&a);
	// printf("B\n");
	// display(&b);
	// printf("------------\n");
	// printf("A\n");
	// push_a(&a, &b);
	// display(&a);
	printf("B\n");
	display(&b);
	free(data);
	free_list(a);
	free_list(b);
	return (0);
}


void	display(t_list **a)
{
	t_list *current;

	current = *a;
	while (current != NULL)
	{
		printf("-- %d\n", current->content);
		current = current->next;
	}
}


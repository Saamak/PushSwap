/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:17:26 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/10 00:57:52 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	b_allocation(t_list **b, t_data *data)
// {
// 	t_list *first;

// 	*b = calloc(sizeof(t_list), 1);
// 	first = *b;
// 	while(data->argv_count > 1)
// 	{
// 		(*b)->next = calloc(sizeof(t_list), 1);
// 		*b = (*b)->next;
// 		data->argv_count--;
// 	}
// 	(*b)->next = NULL;
// 	(*b) = first;
// }

void	first_put_lst(t_list **a, char **charnum_clean)
{
	int i;
	t_list *first;

	i = 0;
	*a = malloc(sizeof(t_list));
	(*a)->content = ft_atoi(charnum_clean[i]);
	first = *a;
	i++;
	while (charnum_clean[i])
	{
		(*a)->next = malloc(sizeof(t_list));
		*a = (*a)->next;
		(*a)->content = ft_atoi(charnum_clean[i]);
		i++;
	}
	(*a)->next = NULL;
	(*a) = first;
}





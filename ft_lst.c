/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:17:26 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/10 20:04:59 by ppitzini         ###   ########.fr       */
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

void	first_put_lst(t_list **a, char **charnum_clean, t_data *data)
{
	int		i;
	t_list	*first;

	i = 0;
	*a = malloc(sizeof(t_list));
	(*a)->content = ft_atoi(charnum_clean[i]);
	(*a)->index = 0;
	first = *a;
	i++;
	while (charnum_clean[i])
	{
		(*a)->next = malloc(sizeof(t_list));
		*a = (*a)->next;
		(*a)->content = ft_atoi(charnum_clean[i]);
		data->index++;
		(*a)->index = data->index;
		i++;
	}
	(*a)->next = NULL;
	(*a) = first;
}

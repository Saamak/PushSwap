/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorythm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:02:06 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/10 20:06:07 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_index(t_list **a, t_data *data)
{
	int		count;
	t_list	*current;
	t_list	*start;
	int		tmp;

	start = (*a);
	count = 0;
	while (data->argv_count > 0 && (*a) != NULL)
	{
		tmp = (*a)->content;
		current = start;
		while (current != NULL)
		{
			if (current->content < tmp)
				count++;
			current = current->next;
		}
		(*a)->index = count;
		if ((*a)->next != NULL)
			(*a) = (*a)->next;
		count = 0;
		data->argv_count--;
	}
	(*a) = start;
}

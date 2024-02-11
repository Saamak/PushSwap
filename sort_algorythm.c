/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorythm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:02:06 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/11 18:27:18 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_index(t_list **a)
{
	int		count;
	t_list	*current;
	t_list	*start;
	int		tmp;

	start = (*a);
	count = 0;
	while ((*a) != NULL)
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
		(*a) = (*a)->next;
		count = 0;
	}
	(*a) = start;
}

int	is_sorted(t_list **a)
{
	t_list	*current;

	current = *a;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_sort_big_list(t_list **a, t_list **b)
{
	int	bit_pos;
	int	size;
	int	count;

	size = ft_lstsize(*a);
	bit_pos = 1;
	while (!(is_sorted(a)))
	{
		count = 0;
		while (*a != NULL && count++ < size)
		{
			if (((*a)->index & bit_pos) == 0)
			{
				push_b(a, b);
			}
			else
				rotate(a);
		}
		while (*b != NULL)
		{
			push_a(a, b);
		}
		bit_pos *= 2;
	}
}

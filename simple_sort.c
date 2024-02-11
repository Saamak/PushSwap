/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:55:06 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/11 20:53:33 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_hub(t_list **a, t_list **b, t_data *data, char **tab)
{
	if (data->argv_count == 2)
		swap_a(a);
	else if (data->argv_count == 3)
		sort_three(a);
	else if (data->argv_count == 4)
		sort_four(a, b);
	else if (data->argv_count == 5)
		sort_five(a, b);
	success(tab, data, a, b);
}

void	sort_three(t_list **a)
{
	while (!is_sorted(a))
	{
		if ((*a)->index > (*a)->next->index)
			swap_a(a);
		else
			reverse_rotate_a(a);
	}
}

void	sort_four(t_list **a, t_list **b)
{
	while (!is_sorted(a))
	{
		push_b(a, b);
		sort_three(a);
		push_a(a, b);
		if ((*a)->content > (*a)->next->content)
			swap_a(a);
	}
}

void	sort_five(t_list **a, t_list **b)
{
	while ((*a)->index != 0)
	{
		if ((*a)->index != 0
			&& (*a)->next->index != 0
			&& (*a)->next->next->index != 0)
			reverse_rotate_a(a);
		else
			rotate(a);
	}
	push_b(a, b);
	while ((*a)->index != 1)
		rotate(a);
	push_b(a, b);
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

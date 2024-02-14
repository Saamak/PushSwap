/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:24:05 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/14 01:57:06 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **x)
{
	t_list	*start;
	t_list	*tmp;

	tmp = (*x)->next;
	start = *x;
	while ((*x)->next != NULL)
		(*x) = (*x)->next;
	(*x)-> next = start;
	start->next = NULL;
	*x = tmp;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_list **a)
{
	t_list	*start;

	start = *a;
	while ((*a)->next->next != NULL)
		(*a) = (*a)->next;
	(*a)->next->next = start;
	start = (*a)->next;
	(*a)->next = NULL;
	(*a) = start;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **b)
{
	t_list	*start;

	start = *b;
	while ((*b)->next->next != NULL)
		(*b) = (*b)->next;
	(*b)->next->next = start;
	start = (*b)->next;
	(*b)->next = NULL;
	(*b) = start;
	write(1, "rrb\n", 4);
}

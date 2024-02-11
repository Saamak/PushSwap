/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:08:09 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/11 18:24:31 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **b)
{
	t_list	*first;
	t_list	*second;

	first = (*b);
	second = (*b)->next;
	first->next = first->next->next;
	second->next = (*b);
	(*b) = second;
	write(2, "sb\n", 3);
}

void	swap_a(t_list **a)
{
	t_list	*first;
	t_list	*second;

	first = (*a);
	second = (*a)->next;
	first->next = first->next->next;
	second->next = (*a);
	(*a) = second;
	write(2, "sa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*topa;

	topa = *a;
	*a = (*a)->next;
	topa->next = *b;
	*b = topa;
	write(2, "pb\n", 3);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*topb;

	topb = *b;
	*b = (*b)->next;
	topb->next = *a;
	*a = topb;
	write(2, "pa\n", 3);
}

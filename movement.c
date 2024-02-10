/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:08:09 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/09 22:41:27 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **x)
{
	t_list *first;
	t_list *second;

	int tmp;
	first = *x;
	second = (*x)->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

void	rotate(t_list **x)
{
	t_list *start;
	t_list *tmp;

	tmp = (*x)->next;
	start = *x;
	while((*x)->next != NULL)
		(*x) = (*x)->next;
	(*x)-> next = start;
	start->next = NULL;
	*x = tmp;
}

void	reverse_rotate(t_list **x)
{
	t_list *start;

	start = *x;
	while((*x)->next->next != NULL)
		(*x) = (*x)->next;
	(*x)->next->next = start;
	start = (*x)->next;
	(*x)->next = NULL;
	(*x) = start;
}

// top num A go to Top of B
void	push_b(t_list **a, t_list **b)
{
    t_list *topA = *a;
    *a = (*a)->next;

    // Add the removed element to the top of list A
    topA->next = *b;
    *b = topA;
}

void	push_a(t_list **a, t_list **b)
{
    t_list *topB = *b;
    *b = (*b)->next;

    // Add the removed element to the top of list A
    topB->next = *a;
    *a = topB;
}

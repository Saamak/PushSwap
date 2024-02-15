/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:05:18 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/15 18:25:21 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_list(t_list **head)
{
	t_list	*current;

	current = (*head);
	while ((*head) != NULL)
	{
		(*head) = (*head)->next;
		free(current);
		current = (*head);
	}
}

void	args_error3(char **tab, t_data *data)
{
	write(2, "Error\n", 6);
	free_tab(tab);
	free(data);
	exit(EXIT_FAILURE);
}

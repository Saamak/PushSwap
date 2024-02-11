/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:04:22 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/11 18:16:10 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_error1(char **tab, t_data *data)
{
	free_tab(tab);
	free(data);
	exit(EXIT_FAILURE);
}

void	simple_error(t_data *data)
{
	write(2, "Error\n", 6);
	free(data);
	exit(EXIT_FAILURE);
}

void	double_error(char **tab, t_data *data, t_list *a)
{
	if (data->i_bool == 1)
		free_tab(tab);
	write(2, "Error\n", 6);
	free_list(a);
	free(data);
	exit(EXIT_FAILURE);
}

void	already_sorted(char **tab, t_data *data, t_list *a)
{
	if (data->i_bool == 1)
		free_tab(tab);
	free_list(a);
	free(data);
	exit(EXIT_FAILURE);
}

void	success(char **tab, t_data *data, t_list *a, t_list *b)
{
	if (data->i_bool == 1)
		free_tab(tab);
	free_list(a);
	if (b != NULL)
		free_list(b);
	free(data);
	exit(EXIT_FAILURE);
}

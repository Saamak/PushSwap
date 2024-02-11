/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:29:16 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/11 20:27:37 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_only_num(char **char_av, t_data *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (char_av[i])
	{
		while (char_av[i][j])
		{
			if (!((char_av[i][j] >= '0' && char_av[i][j] <= '9')
				|| char_av[i][j] == ' '
				|| char_av[i][j] == '+' || char_av[i][j] == '-'))
				args_error1(char_av, data);
			j++;
		}
		i++;
		j = 0;
	}
}

char	**create_av(int ac, char **av, t_data *data)
{
	char	**result;
	char	*args;
	int		i;

	i = 1;
	args = ft_calloc(1, sizeof (char));
	while (i <= (ac - 1))
	{
		args = join_av(args, av[i]);
		i++;
	}
	result = ft_split(args, ' ');
	free(args);
	argv_counter(result, data);
	return (result);
}

char	*join_av(char *args, char *av)
{
	char	*tmp;
	char	*joined;

	tmp = ft_strjoin(av, " ");
	joined = ft_strjoin(args, tmp);
	free (args);
	free (tmp);
	return (joined);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		len_all;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_all = ft_strlenn((char *)s1) + ft_strlenn((char *)s2);
	result = malloc(sizeof(char) * len_all + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

int	check_double(t_list **a)
{
	t_list	*current;
	t_list	*nbr;

	current = *a;
	nbr = *a;
	current = current->next;
	while (nbr != NULL)
	{
		if (current != NULL)
		{
			if (nbr->content == current->content)
				return (1);
			current = current->next;
			if (nbr == current)
				current = current->next;
		}
		else
		{
			nbr = nbr->next;
			current = *a;
		}
	}
	return (0);
}

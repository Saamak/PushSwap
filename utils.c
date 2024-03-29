/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:01:16 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/15 18:41:14 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_data *data, t_list **a, char **tab)
{
	int				i;
	long long int	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = sign * -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - 48;
			i++;
		}
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			double_error(tab, data, a);
		return (result * sign);
	}
	return (0);
}

int	count_words(char const *s, char c)
{
	int	c_w;
	int	tmp;

	tmp = 0;
	c_w = 0;
	while (*s != '\0')
	{
		if (tmp == 1 && *s == c)
			tmp = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			c_w++;
		}
		s++;
	}
	return (c_w);
}

char	**ft_split(char *s, char c)
{
	char	**dest;
	int		i;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (s[0] == c)
			s++;
		else
		{
			i = 0;
			while (s[i] != '\0' && s[i] != c)
				i++;
			dest[x++] = ft_substr(s, 0, i);
			s = s + i;
		}
	}
	dest[x] = NULL;
	return (dest);
}

void	check_sign(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if ((tab[i][j] == '+' && tab[i][j + 1] == '+')
				|| (tab[i][j] == '-' && tab[i][j + 1] == '-'))
				args_error3(tab, data);
			if ((tab[i][j] >= '0' && tab[i][j] <= '9')
				&& (tab[i][j + 1] == '+' || tab[i][j + 1] == '-'))
				args_error3(tab, data);
			if ((tab[i][j] == '+' || (tab[i][j] == '-'))
				&& (!(tab[i][j + 1] >= '0' && tab[i][j + 1] <= '9')))
				args_error3(tab, data);
			j++;
		}
		i++;
		j = 0;
	}
}

void	first_put_lst(t_list **a, char **charnum_clean, t_data *data)
{
	int		i;
	t_list	*first;

	i = 0;
	*a = malloc(sizeof(t_list));
	first = *a;
	(*a)->next = NULL;
	(*a)->content = ft_atoi(charnum_clean[i], data, &first, charnum_clean);
	(*a)->index = 0;
	i++;
	while (charnum_clean[i])
	{
		(*a)->next = malloc(sizeof(t_list));
		*a = (*a)->next;
		(*a)->next = NULL;
		(*a)->content = ft_atoi(charnum_clean[i], data, &first, charnum_clean);
		data->index++;
		(*a)->index = data->index;
		i++;
	}
	(*a)->next = NULL;
	(*a) = first;
}

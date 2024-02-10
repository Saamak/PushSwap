/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:05:44 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/09 23:59:45 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(char *s, int start, int len)
{
	if (start > ft_strlenn(s))
		return (len = 0);
	if (len > ft_strlenn(s) - start)
		return (len = ft_strlenn(s) - start);
	return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	size = check(s, start, len);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int	ft_strlenn(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	argv_counter(char **av, t_data *data)
{
	while(av[data->argv_count])
		data->argv_count++;
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char		*p;
	size_t		sizemax;
	size_t		i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	sizemax = nmemb * size;
	if (sizemax / size != nmemb)
		return (NULL);
	p = malloc(sizemax);
	if (!p)
		return (NULL);
	while (i < sizemax)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

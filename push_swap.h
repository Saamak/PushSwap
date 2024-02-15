/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:28:16 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/15 18:19:03 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct data
{
	int		index;
	int		argv_count;
}	t_data;

// UTILS
int		count_words(char const *s, char c);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str, t_data *data, t_list **a, char **tab);
char	*ft_substr(char *s, int start, int len);
int		check(char *s, int start, int len);
int		ft_strlen(long int n);
int		ft_strlenn(const char *s);
void	argv_counter(char **av, t_data *data);
char	*ft_calloc(size_t nmemb, size_t size);
void	free_tab(char **tab);
void	success(char **tab, t_data *data, t_list **a, t_list **b);

// LIST
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstnew(t_list **a, int content);
void	first_put_lst(t_list **a, char **charnum_clean, t_data *data);
char	**is_one_arg(int ac, char **av, t_data *data);
void	free_list(t_list **head);
t_data	*data_s_init(t_data *data);
int		ft_lstsize(t_list *lst);

// ERROR
void	args_error1(t_data *data);
void	simple_error(t_data *data);
void	double_error(char **tab, t_data *data, t_list **a);
void	already_sorted(char **tab, t_data *data, t_list **a);
void	args_error3(char **tab, t_data *data);

//MOVEMENT
void	swap_a(t_list **a);
void	swap_a(t_list **b);
void	rotate(t_list **x);
void	reverse_rotate_a(t_list **a);
void	reverse_rotate_b(t_list **b);
void	push_b(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);

// PARSING
int		check_double(t_list **a);
void	check_only_num(char **char_av, t_data *data);
void	stack_a_is_sorted(char **tab, t_data *data, t_list **a);
void	check_sign(char **tab, t_data *data);
void	check_quote(char **tab, t_data *data);
void	check_empty(char **av, t_data *data);
void	check_null(char **av, t_data *data);

// ALGLORY
void	find_index(t_list **a);
void	swap_index(t_list **a);
int		check_sorted_index(t_list **a);
int		is_sorted(t_list **a);

void	simple_sort_hub(t_list **a, t_list **b, t_data *data, char **tab);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	ft_sort_big_list(t_list **a, t_list **b);

char	*join_av(char *args, char *av);
char	**create_av(int ac, char **av, t_data *data);
char	*ft_strjoin(char const *s1, char const *s2);
#endif

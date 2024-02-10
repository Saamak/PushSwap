#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int		content;
	struct s_list	*next;
} t_list;

typedef struct data
{
	int		i_bool;
	int		argv_count;
} t_data;

int		count_words(char const *s, char c);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
char	*ft_substr(char *s, int start, int len);
int		check(char *s, int start, int len);
int		ft_strlen(long int n);
int		ft_strlenn(const char *s);
void	argv_counter(char **av, t_data *data);
char	*ft_calloc(size_t nmemb, size_t size);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstnew(t_list **a, int content);
void	first_put_lst(t_list **a, char **charnum_clean);
char	**is_one_arg(int ac, char **av, t_data *data);
void	free_list(t_list *head);
// void	b_allocation(t_list **a, t_data *data);

void	args_error1(char **tab, t_data *data);
void	simple_error(t_data *data);
void	double_error(char **tab, t_data *data, t_list *a);

void	free_tab(char **tab);
void	display(t_list **a);

void	swap(t_list **x);
void	rotate(t_list **x);
void	reverse_rotate(t_list **x);
void	push_b(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);

int		check_double(t_list **a);
void	check_nobody_else(char **av, t_data *data);
void	check_only_num(char **char_av, t_data *data);
void	stack_a_isSorted(char **tab, t_data *data, t_list **a);
void	check_sign(char **tab, t_data *data);

#endif

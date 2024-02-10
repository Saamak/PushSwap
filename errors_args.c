#include "push_swap.h"

void	args_error1(char **tab, t_data *data)
{
	printf("Error : not enought arguments\n");
	free_tab(tab);
	free(data);
	exit(EXIT_FAILURE);
}
void	simple_error(t_data *data)
{
	printf("Error\n");
	free(data);
	exit(EXIT_FAILURE);
}

void	double_error(char **tab, t_data *data, t_list *a)
{
	if (data->i_bool == 1)
		free_tab(tab);
	printf("Error\n");
	free_list(a);
	free(data);
	exit(EXIT_FAILURE);
}

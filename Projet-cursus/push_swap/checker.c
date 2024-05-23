/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:10:13 by mrambelo          #+#    #+#             */
/*   Updated: 2024/05/23 21:18:43 by mariosteven      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i] != NULL)
	{
		if (ft_ispace(str[i]) == 0)
			return (0);
		while (str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) || str[i][j] == ' '
			|| ((str[i][j] == '-' || str[i][j] == '+' )
			&& ft_isdigit(str[i][j + 1])))
				j++;
			else
				return (0);
		}
		if (ft_strncmp(str[i], "", 2) == 0 || ft_strncmp(str[i], " ", 2) == 0)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

char	**check_arg(char **argv)
{
	int		j;
	char	*str;
	char	**new_str;

	j = 2;
	str = ft_strdup(argv[1]);
	while (argv[j] != NULL)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[j++]);
	}
	new_str = ft_split(str, ' ');
	free(str);
	return (new_str);
}

int	check_double(int *nbr, char **new_str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size_new_str(new_str))
	{
		while (j < size_new_str(new_str))
		{
			if (nbr[i] == nbr[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

t_stack	*check_valid(char **argv, int argc)
{
	int		*new_arg;
	t_stack	*a;

	if (argc > 1)
	{
		if (!checker(argv))
		{
			print_error();
			return (0);
		}
		else
		{
			new_arg = char_to_int(check_arg(argv));
			if (new_arg == NULL)
			{
				print_error();
				return (0);
			}
			a = fill_stack_a(new_arg, check_arg(argv));
		}
	}
	return (a);
}

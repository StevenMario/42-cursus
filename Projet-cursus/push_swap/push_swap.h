/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:47:04 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/24 11:50:32 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				above_median;
	int				current_position;
	int				cheapest;
	int				push_price;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		checker(char **str);
int		ft_ispace(char *str);
int		is_sort(t_stack **lst);
int		stack_len(t_stack **lst);
int		*convert_str(char **str);
int		size_new_str(char **new_str);
int		*char_to_int(char **new_str);
int		check_double(int *nbr, char **new_str);
void	print_error(void);
void	swap(t_stack **a);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
void	sort_all(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate(t_stack **lst);
void	free_split(char **str);
void	sort_three(t_stack **lst);
void	ft_lstclear(t_stack **lst);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate(t_stack **lst);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **b, t_stack **a);
void	swap_a_b(t_stack **a, t_stack **b);
void	push(t_stack **lst, t_stack **new);
void	rotate_a_b(t_stack **a, t_stack **b);
void set_target_node_b(t_stack *a, t_stack *b);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	reverse_rotate_a_b(t_stack **a, t_stack **b);
char	**check_arg(char **argv);
t_stack	*ft_double_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack **lst);
t_stack *find_smallest(t_stack *stack);
t_stack	*check_valid(char **argv, int argc);
t_stack	*fill_stack_a(int *new_arg, char **argv);

#endif

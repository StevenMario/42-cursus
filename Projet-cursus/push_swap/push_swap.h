/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariosteven <mariosteven@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:47:04 by mariosteven       #+#    #+#             */
/*   Updated: 2024/05/30 21:45:11 by mariosteven      ###   ########.fr       */
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
	int				cheapest;
	int				push_price;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		checker(char **str);
int		ft_ispace(char *str);
int		is_sort(t_stack **lst);
int		stack_len(t_stack *lst);
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
void move_a_to_b(t_stack **a, t_stack **b);
void move_b_to_a(t_stack **a, t_stack **b);
void set_target_node_b(t_stack *a, t_stack *b);
void set_target_node_a(t_stack *a, t_stack *b);
void set_index_and_median(t_stack *stack);
void set_price_a(t_stack *a, t_stack *b);
t_stack *find_biggest(t_stack *stack);
void min_on_top(t_stack **a);
void set_cheapest(t_stack *b);
void init_stack_a(t_stack *a, t_stack *b);
void init_stack_b(t_stack *a, t_stack *b);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	reverse_rotate_a_b(t_stack **a, t_stack **b);
void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void min_on_top(t_stack **a);
void prep_for_push(t_stack **stack, t_stack *top_stack, char stack_name);
char	**check_arg(char **argv);
t_stack	*ft_double_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack **lst);
t_stack *get_cheapest(t_stack *stack);
t_stack *find_smallest(t_stack *stack);
t_stack	*check_valid(char **argv, int argc);
t_stack	*fill_stack_a(int *new_arg, char **argv);

#endif

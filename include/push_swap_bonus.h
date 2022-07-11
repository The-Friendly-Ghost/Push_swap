/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 14:41:39 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/11 16:32:51 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

typedef struct s_stack {
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

//check_input.c

int		*parse_input(int argc, char **argv);

//create_stack.c

void	create_stack(t_stack **stack, int *numbers, int argc);
void	lstadd_back_ps(t_stack **stack, t_stack *new_element);

//set_index.c
void	set_index(t_stack **a, int argc, int i);

//sa_sb_ss.c

void	swap_a(t_stack **a, int print);
void	swap_b(t_stack **b, int print);
void	swap_ss(t_stack **a, t_stack **b, int print);

//pa_pb.c

void	push_a_to_b(t_stack **a, t_stack **b, int print);
void	push_b_to_a(t_stack **b, t_stack **a, int print);

//ra_rb_rr.c

void	rotate_a(t_stack **a, int print);
void	rotate_b(t_stack **b, int print);
void	rotate_rr(t_stack **a, t_stack **b, int print);

//rra_rrb_rrr.c

void	r_rotate_a(t_stack **a, int print);
void	r_rotate_b(t_stack **b, int print);
void	r_rotate_rr(t_stack **a, t_stack **b, int print);

//sort_utils.c

void	print_a_and_b(t_stack **a, t_stack **b);
int		check_sorted(t_stack **stack);
int		count_elements(t_stack **stack);
int		get_lowest(t_stack **stack);
int		get_highest(t_stack **stack);

//free_stacks.c

void	free_stacks(t_stack **a, t_stack **b);

//bonus_utils.c

int		check_rd(int rd, char *buffer);
void	print_error_and_exit(char *command, t_stack **a, t_stack **b);

#endif
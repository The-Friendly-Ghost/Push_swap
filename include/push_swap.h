/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 13:48:15 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/08 11:32:00 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack {
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves {
	int	elements_a;
	int	elements_b;
	int	a_moves;
	int	a_moves_temp;
	int	a_moves_temp2;
	int	b_moves;
	int	b_moves_temp;
	int	b_moves_temp2;
	int	total_moves;
	int	total_moves_temp;
}	t_moves;

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

//short_sort.c

void	do_short_sort(t_stack **a, int argc);

//sort_middle.c

void	do_middle_sort(t_stack **a, t_stack **b, int argc);

//sort_long.c

void	do_long_sort(t_stack **a, t_stack **b);

//sort_long_presort.c

int		scan_bottom(t_stack **a, int low, int high);
int		scan_top(t_stack **a, int low, int high);
void	presort_elements_to_b(t_stack **a, t_stack **b, int low, int high);
int		get_middle_index(t_stack **a, int low_index);

//sort_long_algorithm.c

void	sort_all(t_stack **a, t_stack **b);
void	reset_moves_struct(t_moves *moves);

//sort_long_moves.c

void	get_best_move(t_stack **a, t_stack **b, t_moves *moves);
void	a_moves_to_fit(t_stack **a, t_moves *moves, int b_index, int lowest);

//sort_long_utils_2.c

void	set_temp_moves_to_zero(t_moves *moves);
void	calculate_total_moves_child(t_moves *moves);
void	execute_move_child(t_stack **a, t_stack **b, t_moves *moves);

//smallest_on_top.c

void	put_smallest_on_top_a(t_stack **a, int argc);
void	put_smallest_on_top_b(t_stack **b, int argc);

//sort_utils.c

void	print_a_and_b(t_stack **a, t_stack **b);
int		check_sorted(t_stack **stack);
int		count_elements(t_stack **stack);
int		get_lowest(t_stack **stack);
int		get_highest(t_stack **stack);

//free_stacks.c

void	free_stacks(t_stack **a, t_stack **b);

#endif
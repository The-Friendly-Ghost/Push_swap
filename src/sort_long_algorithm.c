/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_long_algorithm.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 07:35:21 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/08 11:32:22 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>

/**
Resets all elements in the moves struct to 0
 * @param[in] moves the struct which contains all the moves info
 * @return none
 */
void	reset_moves_struct(t_moves *moves)
{
	moves->elements_a = 0;
	moves->elements_b = 0;
	moves->a_moves = 0;
	moves->a_moves_temp = 0;
	moves->a_moves_temp2 = 0;
	moves->b_moves = 0;
	moves->b_moves_temp = 0;
	moves->b_moves_temp2 = 0;
	moves->total_moves = INT_MAX;
	moves->total_moves_temp = 0;
}

/**
initiates the moves struct
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
static t_moves	*initiate_moves_struct(t_stack **a, t_stack **b)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	if (!moves)
	{
		ft_printf("Moves Allocation Failed");
		free_stacks(a, b);
		exit (1);
	}
	moves->elements_a = 0;
	moves->elements_b = 0;
	moves->a_moves = 0;
	moves->a_moves_temp = 0;
	moves->a_moves_temp2 = 0;
	moves->b_moves = 0;
	moves->b_moves_temp = 0;
	moves->b_moves_temp2 = 0;
	moves->total_moves = 0;
	moves->total_moves_temp = 0;
	return (moves);
}

/**
calculate total moves for the current position
 * @param[in] moves struct that contains multiple variables
 * @return none
 */
static void	execute_move(t_stack **a, t_stack **b, t_moves *moves)
{
	while (moves->a_moves < 0 && moves->b_moves < 0)
	{
		r_rotate_rr(a, b, 1);
		moves->a_moves++;
		moves->b_moves++;
	}
	while (moves->a_moves > 0 && moves->b_moves > 0)
	{
		rotate_rr(a, b, 1);
		moves->a_moves--;
		moves->b_moves--;
	}
	while (moves->a_moves > 0)
	{
		rotate_a(a, 1);
		moves->a_moves--;
	}
	execute_move_child(a, b, moves);
}

/**
Final rotation of a to get index 1 in the first spot
 * @param[in] a stack a
 * @return none
 */
static void	final_rotate(t_stack **a)
{
	t_stack	*temp;
	int		count;
	int		elements;

	temp = *a;
	count = 0;
	elements = count_elements(a);
	while (temp->index != 1)
	{
		temp = temp->next;
		count++;
	}
	if (count > elements / 2)
		count -= elements;
	while (count < 0)
	{
		r_rotate_a(a, 1);
		count++;
	}
	while (count > 0)
	{
		rotate_a(a, 1);
		count--;
	}
}

/**
Now that stack b is presorted, we are going to do the final sorting with this 
function.
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
void	sort_all(t_stack **a, t_stack **b)
{
	t_moves	*moves;

	moves = initiate_moves_struct(a, b);
	while (*b)
	{
		get_best_move(a, b, moves);
		execute_move(a, b, moves);
		push_b_to_a(b, a, 1);
		reset_moves_struct(moves);
	}
	final_rotate(a);
}

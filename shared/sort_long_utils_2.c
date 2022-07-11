/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_long_utils_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 11:20:32 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/08 11:32:43 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
Sets temporaries to zero
 * @param[in] moves moves struct
 * @return none
 */
void	set_temp_moves_to_zero(t_moves *moves)
{
	moves->b_moves_temp = 0;
	moves->b_moves_temp2 = 0;
	moves->a_moves_temp = 0;
	moves->a_moves_temp2 = 0;
	moves->total_moves_temp = 0;
}

/**
Child function of the calculate_total_moves function
 * @param[in] moves struct that contains multiple variables
 * @return none
 */
void	calculate_total_moves_child(t_moves *moves)
{
	while (moves->a_moves_temp2 > 0)
	{
		moves->total_moves_temp++;
		moves->a_moves_temp2--;
	}
	while (moves->a_moves_temp2 < 0)
	{
		moves->total_moves_temp++;
		moves->a_moves_temp2++;
	}
	while (moves->b_moves_temp2 > 0)
	{
		moves->total_moves_temp++;
		moves->b_moves_temp2--;
	}
	while (moves->b_moves_temp2 < 0)
	{
		moves->total_moves_temp++;
		moves->b_moves_temp2++;
	}
}

/**
Child function of execute_move
 * @param[in] moves struct that contains multiple variables
 * @return none
 */
void	execute_move_child(t_stack **a, t_stack **b, t_moves *moves)
{
	while (moves->a_moves < 0)
	{
		r_rotate_a(a, 1);
		moves->a_moves++;
	}
	while (moves->b_moves > 0)
	{
		rotate_b(b, 1);
		moves->b_moves--;
	}
	while (moves->b_moves < 0)
	{
		r_rotate_b(b, 1);
		moves->b_moves++;
	}
}

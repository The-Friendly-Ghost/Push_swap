/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_long_moves.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 08:52:18 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/08 11:27:34 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
Goes to the last element in the stack an returns a pointer to this element
 * @param[in] stack the stack that has to be iterated over
 * @return pointer to last element
 */
t_stack	*list_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

/**
calculate total moves for the current position
 * @param[in] moves struct that contains multiple variables
 * @return none
 */
static void	calculate_total_moves(t_moves *moves)
{
	moves->a_moves_temp2 = moves->a_moves_temp;
	moves->b_moves_temp2 = moves->b_moves_temp;
	while (moves->a_moves_temp2 < 0 && moves->b_moves_temp2 < 0)
	{
		moves->total_moves_temp++;
		moves->a_moves_temp2++;
		moves->b_moves_temp2++;
	}
	while (moves->a_moves_temp2 > 0 && moves->b_moves_temp2 > 0)
	{
		moves->total_moves_temp++;
		moves->a_moves_temp2--;
		moves->b_moves_temp2--;
	}
	calculate_total_moves_child(moves);
}

/**
Determines how many times stack A would have to be rotated to fit the
index of stack B into it.
 * @param[in] a The address of stack b
 * @param[in] temp_b the element to check
 * @param[in] moves struct that contains multiple variables
 * @param[in] lowest could have been initiated inside of the function,, but
 * this helps to keep the function within 25 lines ;)
 * @return none
 */
void	a_moves_to_fit(t_stack **a, t_moves *moves, int b_index, int lowest)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		highest;

	temp = *a;
	temp2 = list_last(*a);
	lowest = get_lowest(a);
	highest = get_highest(a);
	while (temp->next)
	{
		if ((b_index > temp2->index && b_index < temp->index)
			|| (temp->index == highest && b_index > highest)
			|| (temp->index == lowest && b_index < lowest))
			break ;
		if (temp->index == lowest && b_index < lowest)
		{
			moves->a_moves_temp--;
			break ;
		}
		temp2 = temp;
		temp = temp->next;
		moves->a_moves_temp++;
	}
	if (moves->a_moves_temp > (moves->elements_a / 2))
		moves->a_moves_temp -= moves->elements_a;
}

/**
Determines how many positions stack B has to be rotated before a specific
position is on top.
 * @param[in] a The address of stack b
 * @param[in] temp_b the element to check
 * @param[in] moves struct that contains multiple variables
 * @return none
 */
static void	b_moves_to_top(t_stack **b, t_stack *temp_b, t_moves *moves)
{
	t_stack	*temp;

	temp = *b;
moves->elements_b = count_elements(b);
	while (temp->index != temp_b->index)
	{
		moves->b_moves_temp++;
		temp = temp->next;
	}
	if (moves->b_moves_temp > (moves->elements_b / 2))
		moves->b_moves_temp -= moves->elements_b;
}

/**
Gets the position in the a stack for which the lowest amount of moves is
neccesary to sort. In other words, we get the most effectient position to sort.
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
void	get_best_move(t_stack **a, t_stack **b, t_moves *moves)
{
	t_stack	*temp_b;
	t_stack	*temp_a;

	temp_b = *b;
	temp_a = *a;
	if (temp_a->index - 1 == temp_b->index)
		return ;
	moves->elements_a = count_elements(a);
	moves->elements_b = count_elements(b);
	while (temp_b)
	{
		b_moves_to_top(b, temp_b, moves);
		a_moves_to_fit(a, moves, temp_b->index, 0);
		calculate_total_moves(moves);
		if (moves->total_moves_temp < moves->total_moves)
		{
			moves->a_moves = moves->a_moves_temp;
			moves->b_moves = moves->b_moves_temp;
			moves->total_moves = moves->total_moves_temp;
		}
		set_temp_moves_to_zero(moves);
		temp_b = temp_b->next;
		if (!temp_b)
			return ;
	}
}

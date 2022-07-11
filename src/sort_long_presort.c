/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_long_presort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/17 17:33:39 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/04 16:46:56 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/**
Determines the amount of positions that the stack would have to be
rotated to get an elements with an index between low and high on top
 * @param[in] a The address of stack a
 * @param[in] low low end of index to find
 * @param[in] high high end of index to find
 * @return none
 */
int	scan_bottom(t_stack **a, int low, int high)
{
	t_stack	*temp;
	int		elements_from_bottom;
	int		scanned;

	temp = *a;
	elements_from_bottom = 1;
	scanned = 0;
	while (temp)
	{
		if (temp->index >= low && temp->index <= high)
		{
			elements_from_bottom = 1;
			scanned = 1;
		}
		else
			elements_from_bottom++;
		if (!temp->next && scanned == 0)
			return (INT_MAX);
		if (!temp->next && scanned == 1)
			return (elements_from_bottom);
		temp = temp->next;
	}
	return (INT_MAX);
}

/**
Determines the amount of positions that the stack would have to be
rotated to get an elements with an index between low and high on top
 * @param[in] a The address of stack a
 * @param[in] low low end of index to find
 * @param[in] high high end of index to find
 * @return none
 */
int	scan_top(t_stack **a, int low, int high)
{
	t_stack	*temp;
	int		elements_from_top;

	temp = *a;
	elements_from_top = 0;
	while (temp)
	{
		if (temp->index >= low && temp->index <= high)
			return (elements_from_top);
		else
		{
			if (!temp->next)
				return (INT_MAX);
			temp = temp->next;
			elements_from_top++;
		}
	}
	return (INT_MAX);
}

/**
Child function of push_elements_to_b. Rotates stack A until desired index
 is on top
 * @param[in] a The address of stack a
 * @param[in] low_index the lowest index in the a stack
 * @return none
 */
static void	presort_rotate_a(t_stack **a, int top, int bottom, int function)
{
	if (function == 1)
	{
		while (top != 0)
		{
			rotate_a(a, 1);
			top--;
		}
	}
	if (function == 0)
	{
		while (bottom != 0)
		{
			r_rotate_a(a, 1);
			bottom--;
		}
	}
}

/**
First checks if an element has an index between low and high. If that is
the case, then this element will be rotated to the top of stack a and then
pushed to stack b.
 * @param[in] a The address of stack a
 * @param[in] low_index the lowest index in the a stack
 * @return none
 */
void	presort_elements_to_b(t_stack **a, t_stack **b, int low, int high)
{
	t_stack	*temp;
	int		elements_from_top;
	int		elements_from_bottom;

	temp = *a;
	elements_from_bottom = 1;
	while (1)
	{
		elements_from_top = scan_top(a, low, high);
		elements_from_bottom = scan_bottom(a, low, high);
		if (elements_from_bottom == INT_MAX && elements_from_bottom == INT_MAX)
			return ;
		if (elements_from_top <= elements_from_bottom)
			presort_rotate_a(a, elements_from_top, elements_from_bottom, 1);
		if (elements_from_bottom < elements_from_top)
			presort_rotate_a(a, elements_from_top, elements_from_bottom, 0);
		push_a_to_b(a, b, 1);
	}
}

/**
Finds the middle index in the a stack.
 * @param[in] a The address of stack a
 * @param[in] low_index the lowest index in the a stack
 * @return the middle index of the a stack
 */
int	get_middle_index(t_stack **a, int low_index)
{
	int		high_index;
	t_stack	*temp;

	temp = *a;
	high_index = 0;
	while (temp)
	{
		if (temp->index > high_index)
			high_index = temp->index;
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return ((low_index + high_index) / 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallest_on_top.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 13:00:35 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/08 11:10:53 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
Child function of put_smallest_on_top_a. Rotates stack a until the smallest
value is on top. Automatically detects if a reverse rotate of normal rotate 
should be used for minimal amount of moves.
 * @param[in] a the address of stack a
 * @param[in] argc amount of numbers inputted
 * @param[in] index_lowest the position of the list node with lowest value
 * @return none
 */
static void	rotate_smallest_to_top_a(t_stack **a, int argc, int index_lowest)
{
	if (index_lowest > (argc / 2) + 1)
	{
		while (index_lowest <= argc)
		{
			r_rotate_a(a, 1);
			index_lowest++;
		}
	}
	else
	{
		while (index_lowest > 1)
		{
			rotate_a(a, 1);
			index_lowest--;
		}
	}
}

/**
Finds the smallest number on top of stack a and puts it on top.
 * @param[in] a the address of stack a
 * @param[in] argc amount of numbers inputted
 * @return none
 */
void	put_smallest_on_top_a(t_stack **a, int argc)
{
	int		i;
	int		index_lowest;
	int		lowest;
	t_stack	*temp;

	temp = *a;
	lowest = temp->content;
	i = 1;
	index_lowest = 1;
	while (temp->next)
	{
		temp = temp->next;
		i++;
		if (temp->content < lowest)
		{
			lowest = temp->content;
			index_lowest = i;
		}
	}
	rotate_smallest_to_top_a(a, argc, index_lowest);
}

/**
Child function of put_smallest_on_top_b. Rotates stack b until the smallest
value is on top. Automatically detects if a reverse rotate of normal rotate 
should be used for minimal amount of moves.
 * @param[in] b the address of stack b
 * @param[in] argc amount of numbers inputted
 * @param[in] index_lowest the position of the list node with lowest value
 * @return none
 */
static void	rotate_smallest_to_top_b(t_stack **b, int argc, int index_lowest)
{
	if (index_lowest > (argc / 2) + 1)
	{
		while (index_lowest <= argc)
		{
			r_rotate_b(b, 1);
			index_lowest++;
		}
	}
	else
	{
		while (index_lowest > 1)
		{
			rotate_b(b, 1);
			index_lowest--;
		}
	}
}

/**
Finds the smallest number on top of stack b and puts it on top.
 * @param[in] b the address of stack a
 * @param[in] argc amount of numbers inputted
 * @return none
 */
void	put_smallest_on_top_b(t_stack **b, int argc)
{
	int		i;
	int		index_lowest;
	int		lowest;
	t_stack	*temp;

	temp = *b;
	lowest = temp->content;
	i = 1;
	index_lowest = 1;
	while (temp->next)
	{
		temp = temp->next;
		i++;
		if (temp->content < lowest)
		{
			lowest = temp->content;
			index_lowest = i;
		}
	}
	rotate_smallest_to_top_b(b, argc, index_lowest);
}

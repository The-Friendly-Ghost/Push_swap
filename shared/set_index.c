/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_index.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 11:50:47 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/08 11:02:42 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
Creates an index starting from 0 for the lowest value
 * @param[in] a Stack a
 * @return the value of the lowest value in the list
 */
static int	create_first_index(t_stack **stack)
{
	t_stack	*temp;
	int		lowest;

	temp = *stack;
	lowest = temp->content;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->content < lowest)
			lowest = temp->content;
	}
	temp = *stack;
	while (temp->content != lowest)
		temp = temp->next;
	temp->index = 1;
	return (lowest);
}

/**
Small helper function that sets the next lowest int in the set_index function
 * @param[in] a Stack a
 * @return the value of the temporary second lowest value in the list
 */
static int	set_next_lowest(t_stack **a, int lowest)
{
	int		next_lowest;
	t_stack	*temp;

	temp = *a;
	next_lowest = 0;
	while (temp)
	{
		if (temp->content > lowest && temp->index == -1)
		{
			next_lowest = temp->content;
			return (next_lowest);
		}
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return (next_lowest);
}

/**
Creates an index starting from 0 for the lowest value
 * @param[in] a Stack a
 * @param[in] argc Amount of arguments
 * @param[in] i Index i (Just here to keep the function within 25 lines ;) )
 * @return none
 */
void	set_index(t_stack **a, int argc, int i)
{
	int		lowest;
	int		next_lowest;
	t_stack	*temp;

	lowest = create_first_index(a);
	while (i < argc)
	{
		temp = *a;
		next_lowest = set_next_lowest(a, lowest);
		while (temp)
		{
			if (temp->content < next_lowest && temp->index == -1)
				next_lowest = temp->content;
			if (!temp->next)
				break ;
			temp = temp->next;
		}
		temp = *a;
		while (temp->content != next_lowest)
			temp = temp->next;
		temp->index = i + 1;
		i++;
		lowest = next_lowest;
	}
}

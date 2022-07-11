/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 13:22:21 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/23 18:15:59 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

/**
Prints the contents of stack a and b on the stdout in a comprehensable way
 * @param[in] a stack a
 * @param[in] b stack b
 * @return none
 */
void	print_a_and_b(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *a;
	temp_b = *b;
	ft_printf("\na                b\n..................\n");
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			ft_printf("%d", temp_a->content);
			ft_printf(" (%d)", temp_a->index);
			temp_a = temp_a->next;
		}
		if (temp_b)
		{
			ft_printf("                %d", temp_b->content);
			ft_printf(" (%d)", temp_b->index);
			temp_b = temp_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("..................\n\n");
}

/**
Checks if a stack is sorted.
 * @param[in] stack the stack to check
 * @return 0 if not sorted. 1 if sorted.
 */
int	check_sorted(t_stack **stack)
{
	t_stack	*temp;
	int		compare;

	temp = *stack;
	compare = temp->content;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->content < compare)
			return (0);
		compare = temp->content;
	}
	return (1);
}

/**
Counts elements of numbers in a stack
 * @param[in] stack the stack to check
 * @return Amount of elements
 */
int	count_elements(t_stack **stack)
{
	t_stack	*temp;
	int		elements;

	elements = 1;
	temp = *stack;
	if (!temp)
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		elements++;
	}
	return (elements);
}

/**
Returns the lowest index in the stack
 * @param[in] stack the stack to check
 * @return lowest in the stack
 */
int	get_lowest(t_stack **stack)
{
	t_stack	*temp;
	int		index;

	index = INT_MAX;
	temp = *stack;
	while (temp)
	{
		if (temp->index < index)
			index = temp->index;
		temp = temp->next;
		if (!temp)
			break ;
	}
	return (index);
}

/**
Returns the highest index in the stack
 * @param[in] stack the stack to check
 * @return highest in the stack
 */
int	get_highest(t_stack **stack)
{
	t_stack	*temp;
	int		index;

	index = INT_MIN;
	temp = *stack;
	while (temp)
	{
		if (temp->index > index)
			index = temp->index;
		temp = temp->next;
		if (!temp)
			break ;
	}
	return (index);
}

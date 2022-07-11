/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 08:07:15 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/08 11:37:04 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/**
Child function of free_stacks.
 * @param[in] b The address of stack b
 * @return none
 */
static void	free_stacks_child(t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*b)
	{
		temp = *b;
		temp2 = temp;
		while (temp->next)
		{
			temp = temp->next;
			free(temp2);
			temp2 = temp;
			if (!temp->next)
			{
				free(temp);
				break ;
			}
		}
	}
}

/**
Free stack a and stack b
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
void	free_stacks(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*a)
	{
		temp = *a;
		temp2 = temp;
		while (temp->next)
		{
			temp = temp->next;
			free(temp2);
			temp2 = temp;
			if (!temp->next)
			{
				free(temp);
				break ;
			}
		}
	}
	free_stacks_child(b);
}

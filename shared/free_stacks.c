/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 08:07:15 by cpost         #+#    #+#                 */
/*   Updated: 2022/08/03 17:15:25 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <ft_printf.h>

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
		while (temp)
		{
			temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
	}
	if (*b)
	{
		temp = *b;
		while (temp)
		{
			temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
	}
}

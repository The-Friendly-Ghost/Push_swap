/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack_a.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/08 13:42:47 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/05 16:10:55 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

/**
Adds the node ’new_element’ at the end of the linked list.
 * @param[in] stack The address of a pointer to the first link of a list.
 * @param[in] new_element The address of a pointer to the node to be added to
 * the list.
 * @return none
 */
void	lstadd_back_ps(t_stack **stack, t_stack *new_element)
{
	t_stack	*temp;

	if (!*stack)
		*stack = new_element;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_element;
	}
}

/**
 * Creates a new element
 * @param[in] numbers the array with all the numbers in it.
 * @param[in] argc the amount of arguments
 * @return the first element of linked list
 */
static t_stack	*create_element(int *numbers, int i)
{
	t_stack	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->content = numbers[i];
	new_element->next = NULL;
	new_element->index = -1;
	return (new_element);
}

/**
 * Creates the singly linked list which contains all numbers.
 * @param[in] numbers the array with all the numbers in it.
 * @param[in] argc the amount of arguments
 * @return the first node of linked list
 */
void	create_stack(t_stack **stack, int *numbers, int argc)
{
	t_stack	*new_element;
	int		i;

	*stack = create_element(numbers, 0);
	i = 1;
	while (i < argc)
	{
		new_element = create_element(numbers, i);
		if (!new_element)
		{
			ft_printf("Error\n");
			free(numbers);
			free_stacks(stack, NULL);
			exit (1);
		}
		lstadd_back_ps(stack, new_element);
		i++;
	}
}

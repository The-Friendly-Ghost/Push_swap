/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:58 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/07 11:04:29 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
Function:
	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with 
	the value of the parameter ’content’. The variable 
	’next’ is initialized to NULL.
Input: 
	- content: The content to create the node with.
Return value: 
	The new node
*/
t_list	*ft_lstnew(void *content)
{
	struct s_list	*new_block;

	new_block = malloc(sizeof(*new_block));
	if (!new_block)
		return (NULL);
	new_block->content = content;
	new_block->next = NULL;
	return (new_block);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:52:07 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/21 18:51:05 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gcollector_anchor.h"
#include "../includes/gcollector_hash.h"
#include <stdio.h>

/**
 * * gfree
 * 
 * Re-implements the free function.
 * but lookup in hashtable using the hex_key of the ptr;
 * Always set original memory to NULL if its a success.
 * 
 * @param  **ptr: ptr to the memory ptr to free
 * @return : sucess state 
 */

bool	gfree(void **ptr)
{
	t_hashtable			**h;
	t_hashtable_item	*item;
	char				*index;

	if (!ptr || !*ptr)
		return (false);
	h = gc_anchor();
	if (!(*h))
		return (false);
	index = __gc_hash_function(*ptr);
	if (!index)
		return (false);
	item = hashtable_item_get(*h, index, false);
	free(index);
	if (!item)
		return (false);
	hashtable_item_remove(*h, item);
	*ptr = 0;
	return (true);
}

bool	gree(void *ptr)
{
	t_hashtable			**h;
	t_hashtable_item	*item;
	char				*index;

	h = gc_anchor();
	index = __gc_hash_function(ptr);
	if (!ptr || !*h || !index)
		return (false);
	item = hashtable_item_get(*h, index, false);
	free(index);
	if (!item)
		return (false);
	hashtable_item_remove(*h, item);
	return (true);
}

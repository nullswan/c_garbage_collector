/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:52:10 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/21 17:49:41 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gcollector_types.h"
#include "../includes/gcollector_anchor.h"
#include "../includes/gcollector_methods.h"
#include "../includes/gcollector_hash.h"
#include "../includes/gcollector_utils.h"

void	*galloc(size_t size)
{
	t_hashtable			**h;
	t_hashtable_item	*item;
	void				*mem;
	char				*key;

	if (!gc_anchor_exist())
		if (!gc_new(__DEFAULT_GC_SIZE__))
			return (0);
	mem = malloc(size);
	if (!mem)
		return (0);
	__memset(mem, 0, size);
	key = __gc_hash_function(mem);
	if (!key)
	{
		free(mem);
		return (0);
	}
	h = gc_anchor();
	item = hashtable_insert(h, key, mem);
	if (!item)
		return (0);
	return (item->value);
}

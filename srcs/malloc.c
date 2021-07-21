/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:52:10 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/21 17:55:44 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gcollector_types.h"
#include "../includes/gcollector_anchor.h"
#include "../includes/gcollector_methods.h"
#include "../includes/gcollector_hash.h"
#include "../includes/gcollector_utils.h"

static void	*__assign_error(char **key, void **mem)
{
	if (key && *key)
	{
		free(*key);
		*key = 0;
	}
	if (mem && *mem)
	{
		free(*mem);
		*mem = 0;
	}
	return (0);
}

static void	*__assign_new_node(t_hashtable **hashtable, char **key, void **mem)
{
	t_hashtable_item	*item;

	item = hashtable_insert(hashtable, *key, *mem);
	if (item)
		return (item->value);
	return (__assign_error(key, mem));
}

void	*galloc(size_t size)
{
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
		return (__assign_error(&key, 0));
	return (__assign_new_node(gc_anchor(), &key, &mem));
}

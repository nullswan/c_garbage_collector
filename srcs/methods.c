/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:51:36 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 03:12:20 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gcollector_types.h"
#include "../includes/gcollector_anchor.h"

t_hashtable	*gc_new(unsigned int size)
{
	t_hashtable	*hashtable;

	if (size == 0)
		return (false);
	hashtable = hashtable_new(size);
	if (!hashtable)
		return (false);
	(*(gc_anchor())) = hashtable;
	return (*(gc_anchor()));
}

bool	gc_destroy(void)
{
	t_hashtable	**hashtable;

	hashtable = gc_anchor();
	if (!*hashtable || !hashtable)
		return (true);
	hashtable_destroy(hashtable, true);
	return (gc_anchor() == 0);
}

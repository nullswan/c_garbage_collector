/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:23:36 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 03:35:42 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gcollector_utils.h"
#include "../includes/gcollector_types.h"

char	*__gc_hash_function(void *ptr)
{
	if (!ptr)
		return (0);
	return (__itoa_base((size_t)ptr, 16));
}

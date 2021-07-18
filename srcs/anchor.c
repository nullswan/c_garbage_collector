/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anchor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:51:53 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 03:17:14 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gcollector_types.h"

t_hashtable	**gc_anchor(void)
{
	static t_hashtable	*hashtable = false;

	return (&hashtable);
}

bool	gc_anchor_exist(void)
{
	return (*gc_anchor() != 0);
}

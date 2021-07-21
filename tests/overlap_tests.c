/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:27:54 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/21 18:29:35 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static bool	overlap_double_new(void)
{
	gc_new(10);
	gc_new(10);
	gc_destroy();
	return (true);
}

bool	overlap_tests(void)
{
	if (!overlap_double_new())
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:00:58 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 09:39:09 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static bool	malloc_one_and_destroy(void)
{
	void	*ptr;

	ptr = galloc(10);
	if (!ptr)
		return (error(TEST_MALLOC_1, FAL));
	gc_destroy();
	return (success(TEST_MALLOC_1, SUC));
}

static bool	malloc_one_and_manual_free(void)
{
	void	*ptr;

	ptr = galloc(10);
	if (!ptr)
		return (error(TEST_MALLOC_2, FAL));
	if (!gfree(&ptr))
		return (error(TEST_MALLOC_2, FAL));
	gc_destroy();
	return (true);
}

static bool	malloc_gc_overflow(void)
{
	void	*ptr;
	int		i;

	gc_new(50);
	i = -1;
	while (++i < 100)
	{
		ptr = galloc(100);
		if (!ptr)
		{
			gc_destroy();
			return (error(TEST_MALLOC_3, FAL));
		}
	}
	gc_destroy();
	return (success(TEST_MALLOC_3, SUC));
}

static bool	malloc_gc_huge(void)
{
	void	*ptr;
	int		i;

	gc_new(50000);
	i = -1;
	while (++i < 100000)
	{
		ptr = galloc(100);
		if (!ptr)
		{
			gc_destroy();
			return (error(TEST_MALLOC_4, FAL));
		}
	}
	gc_destroy();
	return (success(TEST_MALLOC_4, SUC));
}

bool	malloc_tests(void)
{
	if (!malloc_one_and_destroy())
		return (false);
	if (!malloc_one_and_manual_free())
		return (false);
	if (!malloc_gc_overflow())
		return (false);
	if (!malloc_gc_huge())
		return (false);
	return (true);
}

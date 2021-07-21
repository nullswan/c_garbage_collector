/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:43:52 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/21 18:52:37 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static bool	free_on_nilgc(void)
{
	void	*ptr;

	ptr = NULL;
	if (gfree(&ptr))
		return (error(TEST_FREE_1, FAL));
	ptr = malloc(10);
	if (gfree(&ptr))
	{
		free(ptr);
		return (error(TEST_FREE_1, FAL));
	}
	free(ptr);
	return (success(TEST_FREE_1, SUC));
}

static bool	free_unexisting(void)
{
	void	*ptr;

	ptr = malloc(10);
	gc_new(10);
	if (gfree(&ptr))
	{
		free(ptr);
		gc_destroy();
		return (error(TEST_FREE_2, FAL));
	}
	free(ptr);
	gc_destroy();
	return (success(TEST_FREE_2, SUC));
}

static bool	gree_test(void)
{
	void	*ptr;

	gc_new(10);
	ptr = gc_new(10);
	gree(ptr);
	if (!ptr)
		return (error(TEST_FREE_3, FAL));
	gc_destroy();
	return (success(TEST_FREE_3, SUC));
}

bool	free_tests(void)
{
	if (!free_on_nilgc())
		return (false);
	if (!free_unexisting())
		return (false);
	if (!gree_test())
		return (false);
	return (true);
}

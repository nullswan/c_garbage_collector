/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:07:19 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 04:03:10 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static bool	create_and_destroy_gc(void)
{
	gc_new(100);
	gc_destroy();
	if (gc_anchor_exist())
		return (error(TEST_BASIC_1, FAL));
	return (success(TEST_BASIC_1, SUC));
}

static bool	create_null_gc(void)
{
	gc_new(0);
	gc_destroy();
	if (gc_anchor_exist())
		return (error(TEST_BASIC_2, FAL));
	return (success(TEST_BASIC_2, SUC));
}

static bool	test_itoa_base(void)
{
	char	*ret;

	ret = __itoa_base(0, 16);
	if (strcmp(ret, "0") != 0)
		return (error(TEST_BASIC_3, FAL));
	free(ret);
	ret = __itoa_base(100, 16);
	if (strcmp(ret, "64") != 0)
		return (error(TEST_BASIC_3, FAL));
	free(ret);
	return (success(TEST_BASIC_3, SUC));
}

bool	basic_tests(void)
{
	if (!create_and_destroy_gc())
		return (false);
	if (!create_null_gc())
		return (false);
	if (!test_itoa_base())
		return (false);
	return (true);
}

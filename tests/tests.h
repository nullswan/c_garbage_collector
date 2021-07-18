/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:35:09 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 09:46:00 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <string.h>
# include "../includes/gcollector.h"
# include "../includes/gcollector_utils.h"

# define SUC "SUCCESS"
# define FAL "FAILURE"
# define TEST_BASIC_1 "CREATE_AND_DESTROY_GC"
# define TEST_BASIC_2 "CREATE_NULL_GC"
# define TEST_BASIC_3 "TEST_ITOA_BASE"
# define TEST_BASIC_4 "TEST_ITER"
# define TEST_FREE_1 "FREE_ON_NILGC"
# define TEST_FREE_2 "FREE_UNEXISTING"
# define TEST_MALLOC_1 "MALLOC_ONE_AND_DESTROY"
# define TEST_MALLOC_2 "MALLOC_ONE_AND_MANUAL_FREE"
# define TEST_MALLOC_3 "MALLOC_GC_OVERFLOW"
# define TEST_MALLOC_4 "MALLOC_GC_HUGE"

bool	basic_tests(void);
bool	free_tests(void);
bool	malloc_tests(void);
bool	error(char *test_name, char *error);
bool	success(char *test_name, char *error);

#endif
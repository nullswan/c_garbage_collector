/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:34:58 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 04:01:43 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	if (!basic_tests())
		return (EXIT_FAILURE);
	if (!free_tests())
		return (EXIT_FAILURE);
	if (!malloc_tests())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

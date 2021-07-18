/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:13:37 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 03:47:57 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	msg(char *test_name, char *error)
{
	printf("[!] %s: %s\n", test_name, error);
}

bool	error(char *test_name, char *error)
{
	msg(test_name, error);
	return (false);
}

bool	success(char *test_name, char *error)
{
	msg(test_name, error);
	return (true);
}

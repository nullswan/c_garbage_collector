/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:25:52 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 04:56:55 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	__hex_conv(int nbr)
{
	if (nbr >= 10)
		return (nbr - 10 + 'a');
	else
		return (nbr + '0');
}

static int	__nbr_len(int nbr, int base)
{
	int	i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		++i;
	}
	return (i);
}

char	*__itoa_base(size_t nbr, unsigned int base)
{
	char	*ret;
	int		nbr_length;

	nbr_length = __nbr_len(nbr, base);
	ret = (char *)malloc(sizeof(char) * (nbr_length + 1));
	if (!ret)
		return (0);
	ret[nbr_length] = 0;
	while (--nbr_length >= 0)
	{
		ret[nbr_length] = __hex_conv(nbr % base);
		nbr /= base;
	}
	return (ret);
}

void	*__memset(void *s, int c, size_t n)
{
	void	*save;

	save = s;
	while (n--)
		*(unsigned char *)s++ = (unsigned char)c;
	return (save);
}

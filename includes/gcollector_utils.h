/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcollector_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:31:31 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 09:36:30 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCOLLECTOR_UTILS_H
# define GCOLLECTOR_UTILS_H

# include <stdlib.h>

char	*__itoa_base(size_t nbr, unsigned int base);
void	*__memset(void *s, int c, size_t n);

#endif
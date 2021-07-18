/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcollector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 02:14:29 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 04:03:39 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCOLLECTOR_H
# define GCOLLECTOR_H

# include "gcollector_methods.h"
# include "gcollector_anchor.h"

bool	gfree(void **ptr);
void	*galloc(size_t size);

#endif
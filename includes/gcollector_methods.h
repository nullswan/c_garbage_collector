/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcollector_methods.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:04:31 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 03:09:45 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCOLLECTOR_METHODS_H
# define GCOLLECTOR_METHODS_H

# include "gcollector_types.h"

t_hashtable	*gc_new(unsigned int size);
bool		gc_destroy(void);

#endif
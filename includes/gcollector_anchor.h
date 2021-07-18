/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcollector_anchor.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c3b5aw <dev@c3b5aw.dev>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:03:26 by c3b5aw            #+#    #+#             */
/*   Updated: 2021/07/18 03:17:22 by c3b5aw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCOLLECTOR_ANCHOR_H
# define GCOLLECTOR_ANCHOR_H

# include "gcollector_types.h"

t_hashtable	**gc_anchor(void);
bool		gc_anchor_exist(void);

#endif
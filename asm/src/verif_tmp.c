/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 20:55:33 by iburel            #+#    #+#             */
/*   Updated: 2017/09/11 21:23:16 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		verif_tmp(t_tmplb *tmp)
{
	while (tmp)
	{
		if (tmp->name[0])
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
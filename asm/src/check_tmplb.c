/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tmplb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:30:49 by iburel            #+#    #+#             */
/*   Updated: 2017/11/29 17:06:40 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_tmplb(t_label *labels)
{
	t_tmplb	*tmp;
	int		error;
	int		addr;

	tmp = labels->tmp;
	while (tmp)
	{
		if (tmp->name[0])
		{
			addr = ft_bc(tmp->name, labels, &error, tmp->rel);
			if (error)
				return (puterror(ERROR_BAD_LABEL, 0));
			buff_atcursor(addr, tmp->cursor, tmp->size);
		}
		tmp = tmp->next;
	}
	return (1);
}

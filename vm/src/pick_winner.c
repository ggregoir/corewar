/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_winner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:42:15 by niragne           #+#    #+#             */
/*   Updated: 2018/02/18 18:56:22 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		pick_winner(void)
{
	int			max;
	t_uint32	i;
	t_uint32	j;

	max = -1;
	i = 1;
	while (i <= g_nb_player)
	{
		if ((int)g_champs[i].live > max)
		{
			max = (int)g_champs[i].live;
			j = i;
		}
		i++;
	}
	return (j);
}

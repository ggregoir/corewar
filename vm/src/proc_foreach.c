/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:55:44 by niragne           #+#    #+#             */
/*   Updated: 2017/11/29 15:13:42 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    proc_foreach(t_proc **cycle, t_uint32 nb_cycle)
{
    t_uint32    pos;
    t_proc      *tmp;
    t_proc      *tmp2;
    
    pos = nb_cycle % 1001;
    tmp = cycle[pos];
    while (tmp)
    {
        tmp2 = tmp->next;
        //debug_cycle(cycle);
        //debug_proc(tmp);
        exec_proc(cycle, nb_cycle, tmp);
        cycle[pos] = tmp2;
        tmp = tmp2;
    }
}
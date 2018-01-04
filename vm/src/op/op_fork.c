/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:19:08 by root              #+#    #+#             */
/*   Updated: 2018/01/04 18:40:15 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_fork(t_proc *p, t_inst *args, t_int32 g_nb_cycle, t_proc **procs)
{
    t_proc  *new;
    t_int32 tmp;
    char    str[CHAT_LINE_SIZE];
    
    tmp = (args[0].value % IDX_MOD + p->pc);
    tmp = tmp % MEM_SIZE + MEM_SIZE * (tmp < 0);
    new = create_proc(p, tmp, g_nb_cycle);
    if (g_mem[new->pc] == 0 || g_mem[new->pc] > 16)
        insert_proc(procs, new, (g_nb_cycle + 1) % 1001);
    else
        insert_proc(procs, new, (g_nb_cycle + op_tab[g_mem[new->pc]].cycles) % 1001);
    sprintf(str, "[%6d] Process %4d created by player %.15s at index %4d", g_nb_cycle, new->id, g_champs[p->player].name, new->pc);
    add_line_chat(str);
}

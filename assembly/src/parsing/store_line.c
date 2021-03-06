/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:42:50 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/12 13:26:41 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			store_line(t_tab *tab, t_tab *current, t_visual *win)
{
	if (!(g_option & VISUAL_FLAG))
	{
		ft_memdel((void**)&current->line);
		current->line = 0;
		return (1);
	}
	if (g_lines == win->size.y)
		run_visual(tab, win);
	tab[g_lines].line = current->line;
	tab[g_lines].ptr = current->ptr;
	tab[g_lines].size = current->size;
	g_lines++;
	return (1);
}

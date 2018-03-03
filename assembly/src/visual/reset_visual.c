/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:46:28 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/03 19:07:06 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		reset_visual(t_visual *win, char *name)
{
	int		size;

	size = ft_strlen(name);
	wait_end();
	werase(win->as);
	werase(win->bin);
	erase();
	wrefresh(win->as);
	wrefresh(win->bin);
	refresh();
	attron(COLOR_PAIR(NC_YELLOW) | A_BOLD);
	if (g_error[0])
	{
		mvprintw(LINES / 2, (COLS - ft_strlen(g_error)) / 2, g_error);
		mvprintw(LINES / 2 + 2, (COLS - size - 18) / 2, ERROR_MSG, name);
	}
	else
		mvprintw(LINES / 2, (COLS - size - 20) / 2, COMPILE_MSG, name);
	mvprintw(LINES / 2 + 4, (COLS - 38) / 2, NEXT_MANUAL);
	attroff(COLOR_PAIR(NC_YELLOW));
	wait_end();
	erase();
	wprintw(win->bin, "\n\n\n\t");
	win->cur.x = 0;
	win->cur.y = 0;
}

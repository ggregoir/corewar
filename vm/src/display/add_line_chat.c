/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_chat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:52:54 by iburel            #+#    #+#             */
/*   Updated: 2018/02/12 14:30:13 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	add_line_chat(char *str)
{
	int		tmp;

	tmp = (g_line_chat + 1) % CHAT_SIZE;
	ft_memcpy(g_chat[tmp], str, CHAT_LINE_SIZE);
	g_line_chat = tmp;
}
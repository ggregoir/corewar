/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:12:53 by niragne           #+#    #+#             */
/*   Updated: 2018/01/30 09:37:57 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    end_game(void)
{
    char            str[CHAT_LINE_SIZE];

    ft_memset(str, '-', sizeof(str) - 1);
    str[sizeof(str) - 1] = 0;
    add_line_chat(str);
    ft_sprintf(str, "%.20s won the game.", g_champs[pick_winner()].name);
    add_line_chat(str);
}
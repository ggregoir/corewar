/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:27:58 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/10 23:49:37 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		word_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\t' && str[i] != ' ' &&
			str[i] != SEPARATOR_CHAR && str[i])
		i++;
	return (i);
}
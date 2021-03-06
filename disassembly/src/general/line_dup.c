/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:54:02 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/13 21:52:34 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

char		*line_dup(char *line, size_t n)
{
	char	*new;
	size_t	i;

	if (!(new = malloc(sizeof(*new) * (n + 1))))
	{
		print_error(strerror(errno));
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		new[i] = line[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

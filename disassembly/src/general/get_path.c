/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:08:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/12 18:13:19 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

char	*get_path(char *file)
{
	char	*name;
	size_t	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp(file + len - 4, ".cor"))
	{
		print_error(BAD_EXTENSION, file);
		return (NULL);
	}
	if (!(name = malloc(sizeof(*name) * (len - 1))))
	{
		print_error(strerror(errno));
		return (NULL);
	}
	ft_strncpy(name, file, len - 4);
	ft_strcpy(name + len - 4, ".s");
	return (name);
}

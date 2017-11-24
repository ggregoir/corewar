/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:23:24 by iburel            #+#    #+#             */
/*   Updated: 2017/02/09 17:12:58 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;
	size_t	size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
	{
		tmp = ft_strdup(s2);
		return (tmp);
	}
	else if (s2 == NULL)
	{
		tmp = ft_strdup(s1);
		return (tmp);
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (size + 1))))
		return (NULL);
	ft_strcpy(tmp, s1);
	ft_strcat(tmp, s2);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:24:26 by iburel            #+#    #+#             */
/*   Updated: 2017/04/21 17:53:07 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_if(int fd, int size, t_uchar **buf, int *p)
{
	if (!*buf)
	{
		if (!(*buf = (t_uchar *)malloc(sizeof(**buf) * BUFF_SIZE)))
			ft_afferror("error malloc in ft_buf");
	}
	if (size == -1)
	{
		write(fd, *buf, *p);
		*p = 0;
		return (0);
	}
	if (*p + size > BUFF_SIZE)
	{
		write(fd, *buf, *p);
		*p = 0;
	}
	return (1);
}

static void	ft_bufcpy(t_uchar *buf, int *p, void *str, int size)
{
	t_ulint	*tmp1;
	t_ulint	*tmp2;
	t_uchar	*tmp3;
	int		i;

	tmp1 = (t_ulint *)buf;
	tmp2 = (t_ulint *)str;
	tmp3 = (t_uchar *)str;
	i = 0;
	while (size >= 8)
	{
		tmp1[i] = tmp2[i];
		i++;
		size -= 8;
		*p += 8;
	}
	i *= 8;
	while (size > 0)
	{
		buf[i] = tmp3[i];
		i++;
		size--;
		(*p)++;
	}
}

int			ft_buf(int fd, void *str, int size)
{
	static t_uchar	*buf = NULL;
	static int		p = 0;

	if (!ft_if(fd, size, &buf, &p))
		return (p);
	if (size > BUFF_SIZE)
	{
		write(fd, str, size);
		return (size);
	}
	ft_bufcpy(buf + p, &p, str, size);
	return (0);
}

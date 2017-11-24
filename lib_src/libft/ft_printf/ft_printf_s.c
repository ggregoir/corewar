/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:44:06 by iburel            #+#    #+#             */
/*   Updated: 2017/04/17 19:12:31 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_addopt(int size, char *str, t_flags *flags)
{
	int		sp;

	if (size > flags->prec && (FLAGS & FPREC))
		size = flags->prec;
	sp = flags->blanks - size;
	if (!(flags->flags & FSUB) && sp > 0)
		ft_printf_strnew(' ' + 16 * ((FLAGS & FZE) > 0), sp, FD);
	ft_buf(FD, str, size);
	if (flags->flags & FSUB && sp > 0)
		ft_printf_strnew(' ', sp, FD);
	return (size + sp * (sp > 0));
}

int			ft_printf_s(t_flags *flags, va_list ap)
{
	int		size;
	int		tmp;
	char	*str;

	if (TYPE == FL)
		return (ft_printf_ls(va_arg(ap, wchar_t *), flags));
	str = va_arg(ap, char *);
	tmp = 0;
	if (!str)
	{
		size = 6;
		if (!(str = (char *)malloc(sizeof(*str) * 7)))
			ft_afferror("error malloc in ft_printf_s");
		ft_strcpy(str, "(null)");
		tmp = 1;
	}
	else
		size = ft_strlen(str);
	if (flags->prec < 0)
		flags->prec = size;
	size = ft_addopt(size, str, flags);
	if (tmp)
		free(str);
	return (size);
}

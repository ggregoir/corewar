/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_k.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:07:26 by iburel            #+#    #+#             */
/*   Updated: 2017/04/16 21:16:29 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_addopt(int size, char *str, t_flags *flags)
{
	int		sp;

	sp = flags->blanks - size;
	if (!(flags->flags & FSUB) && sp > 0)
		ft_printf_strnew(' ' + 16 * ((FLAGS & FZE) > 0), sp, FD);
	ft_buf(FD, str, size);
	if (flags->flags & FSUB && sp > 0)
		ft_printf_strnew(' ', sp, FD);
	return (size + sp * (sp > 0));
}

int			ft_printf_k(t_flags *flags, va_list ap)
{
	int		size;
	char	*str;
	time_t	k;

	k = va_arg(ap, time_t);
	if (!(FLAGS & FPREC))
		flags->prec = 2;
	size = ft_printf_ktoa(k, &str);
	size = ft_addopt(size, str, flags);
	free(str);
	return (size);
}

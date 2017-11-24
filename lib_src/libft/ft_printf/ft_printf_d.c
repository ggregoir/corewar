/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:41:02 by iburel            #+#    #+#             */
/*   Updated: 2017/04/16 21:15:30 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_initopt(int opt[5], int size, t_flags *flags, char c)
{
	PREC = flags->prec - size + 1 * (c == '-');
	ADDORSPACE = (FLAGS & (FADD + FSPACE)) && c != '-';
	BLANKS = flags->blanks - size - PREC * (PREC > 0) - ADDORSPACE;
	if (!(FLAGS & FPREC) && (FLAGS & FZE) && !(FLAGS & FSUB))
	{
		PREC = flags->blanks - size - ADDORSPACE;
		BLANKS = 0;
	}
}

static int	ft_addopt(int size, char *str, t_flags *flags, int zero)
{
	int		opt[5];

	ft_initopt(opt, size, flags, str[0]);
	ZERO = ((FLAGS & FPREC) && (flags->prec == 0) && zero);
	BLANKS += ZERO;
	if (!(FLAGS & FSUB) && BLANKS > 0)
		ft_printf_strnew(' ', BLANKS, FD);
	if ((FLAGS & FADD) && str[0] != '-')
		ft_buf(FD, "+", 1);
	else if ((FLAGS & FSPACE) && str[0] != '-')
		ft_buf(FD, " ", 1);
	if (str[0] == '-')
		ft_buf(FD, str, 1);
	if (PREC > 0)
		ft_printf_strnew('0', PREC, FD);
	if (ZERO)
		size -= 1;
	else
		ft_buf(FD, str + 1 * (str[0] == '-'), size - 1 * (str[0] == '-'));
	if ((FLAGS & FSUB) && BLANKS > 0)
		ft_printf_strnew(' ', BLANKS, FD);
	return (size + PREC * (PREC > 0) + ADDORSPACE + BLANKS * (BLANKS > 0));
}

int			ft_printf_d(t_flags *flags, va_list ap)
{
	char	*str;
	int		size;
	t_llint	nbr;

	nbr = va_arg(ap, t_llint);
	ft_getstype(TYPE, &nbr);
	size = ft_printf_itoa(nbr, &str);
	size = ft_addopt(size, str, flags, nbr == 0);
	free(str);
	return (size);
}

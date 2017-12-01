/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_la.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:50:24 by iburel            #+#    #+#             */
/*   Updated: 2017/04/05 17:05:45 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_initopt(int opt[4], int size, t_flags *flags, char c)
{
	ADDORSPACE = (FLAGS & (FADD + FSPACE)) > 0 && c != '-';
	BLANKS = flags->blanks - size - ADDORSPACE;
	SUB = c == '-';
}

static int	ft_addopt(int size, char *str, t_flags *flags)
{
	int		opt[4];

	ft_initopt(opt, size, flags, str[0]);
	if (BLANKS > 0 && !(FLAGS & FSUB) && !(FLAGS & FZE))
		ft_printf_strnew(' ', BLANKS, FD);
	if (FLAGS & FADD && str[0] != '-')
		ft_buf(FD, "+", 1);
	else if (FLAGS & FSPACE && str[0] != '-')
		ft_buf(FD, " ", 1);
	if (SUB)
		ft_buf(FD, str, 1);
	if (FLAGS & FMAJ)
		ft_buf(FD, "0X", 2);
	else
		ft_buf(FD, "0x", 2);
	if (BLANKS > 0 && !(FLAGS & FSUB) && (FLAGS & FZE))
		ft_printf_strnew('0', BLANKS, FD);
	ft_buf(FD, str + SUB, size - SUB);
	if (BLANKS > 0 && (FLAGS & FSUB))
		ft_printf_strnew(' ', BLANKS, FD);
	return (size + ADDORSPACE + BLANKS * (BLANKS > 0) + 2);
}

static int	ft_prec(char *str)
{
	int		size;

	size = ft_strlen(str);
	if (*(str + size - 1) >= '5')
	{
		while (*(str - 1) == '9')
		{
			str--;
			*str = '0';
		}
		str--;
		if (*str != '.')
			*str += 1;
		else
			*(str - 1) += 1;
	}
	return (size);
}

static int	ft_tronc(char *str)
{
	int		i;

	i = 0;
	while (*(str - i) == '0')
		i++;
	if (i > 0)
		ft_memmove(str - i + 1, str + 1, ft_strlen(str));
	return (i);
}

int			ft_printf_la(t_ldouble nbr, t_flags *flags)
{
	int		size;
	int		len;
	char	*str;

	len = 0;
	size = ft_printf_dtoa_la(nbr, flags, &str);
	if (flags->prec >= 0)
	{
		len = ft_prec(str + size);
		size -= ft_tronc(str + size - 1);
	}
	size = ft_addopt(size + len - 1, str, flags);
	free(str);
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lg_le.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:00:17 by iburel            #+#    #+#             */
/*   Updated: 2017/04/04 13:01:20 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_initopt(int opt[4], int size, t_flags *flags, char c)
{
	ADDORSPACE = (FLAGS & (FADD + FSPACE)) > 0 && c != '-';
	BLANKS = flags->blanks - size - ADDORSPACE;
	SUB = BLANKS > 0 && !(FLAGS & FSUB) && (FLAGS & FZE) && c == '-';
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
	if (BLANKS > 0 && !(FLAGS & FSUB) && (FLAGS & FZE))
		ft_printf_strnew('0', BLANKS, FD);
	ft_buf(FD, str + SUB, size - SUB);
	if (BLANKS > 0 && (FLAGS & FSUB))
		ft_printf_strnew(' ', BLANKS, FD);
	return (size + ADDORSPACE + BLANKS * (BLANKS > 0));
}

static void	ft_prec(char *str)
{
	if (*(str + 4) >= '5')
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
}

static int	ft_tronc(char *str)
{
	int		i;

	i = 0;
	while (*(str - i) == '0')
		i++;
	if (i > 0)
		ft_memmove(str - i + 1, str + 1, 4);
	return (i);
}

int			ft_printf_lg_le(t_ldouble nbr, t_flags *flags)
{
	int		size;
	char	*str;

	size = ft_printf_dtoa_lg_le(nbr, flags, &str);
	if (flags->prec >= 0)
	{
		ft_prec(str + size - 4);
		size -= ft_tronc(str + size - 5);
	}
	size = ft_addopt(size, str, flags);
	free(str);
	return (size);
}

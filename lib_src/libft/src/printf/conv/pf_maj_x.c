/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_maj_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:56:40 by root              #+#    #+#             */
/*   Updated: 2017/12/16 21:19:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void pf_put_maj_x(t_pfflags *flags, int size, int test, char *str)
{
    if (!flags->tags.minus)
    {
        if (!flags->tags.zero)
        {
            pf_fill(flags->blank, ' ');
            if (test)
                g_pf_buff("0X", 2);
            pf_fill(flags->prec, '0');
            g_pf_buff(str, size);
        }
        else
        {
            if (test)
                g_pf_buff("0X", 2);
            pf_fill(flags->blank + flags->prec, '0');
            g_pf_buff(str, size);
        }
    }
    else
    {
        if (test)
            g_pf_buff("0X", 2);
        pf_fill(flags->prec, '0');
        g_pf_buff(str, size);
        pf_fill(flags->blank, ' ');
    }
}

int     pf_maj_x(va_list arg, t_pfflags *flags)
{
    char        str[20];
    t_int64     n;
    int         size;
    int         test;

    n = g_type[flags->type](arg);
    size = pf_uitoa_base(str, n, 16, 1);
    test = flags->tags.hashtag * 2;
    flags->prec -= size + test;
    flags->prec *= (flags->prec <= INT_MAX);
    flags->blank -= size + test + flags->prec;
    flags->blank *= (flags->blank <= INT_MAX);
    pf_put_maj_x(flags, size, test, str);
    return (size + flags->prec + flags->blank + test);
}
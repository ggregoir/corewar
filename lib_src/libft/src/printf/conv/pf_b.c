/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:05 by root              #+#    #+#             */
/*   Updated: 2017/12/16 21:19:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void pf_put_b(t_pfflags *flags, int size, int test, char *str)
{
    if (!flags->tags.minus)
    {
        if (!flags->tags.zero)
        {
            pf_fill(flags->blank, ' ');
            if (test)
                g_pf_buff("0b", 2);
            pf_fill(flags->prec, '0');
            g_pf_buff(str, size);
        }
        else
        {
            if (test)
                g_pf_buff("0b", 2);
            pf_fill(flags->blank + flags->prec, '0');
            g_pf_buff(str, size);
        }
    }
    else
    {
        if (test)
            g_pf_buff("0b", 2);
        pf_fill(flags->prec, '0');
        g_pf_buff(str, size);
        pf_fill(flags->blank, ' ');
    }
}

int         pf_b(va_list arg, t_pfflags *flags)
{
    char        str[70];
    t_int64     n;
    int         size;
    int         test;

    n = g_type[flags->type](arg);
    size = pf_uitoa_base(str, n, 2, 0);
    test = flags->tags.hashtag * 2;
    flags->prec -= size + test;
    flags->prec *= (flags->prec <= INT_MAX);
    flags->blank -= size + test + flags->prec;
    flags->blank *= (flags->blank <= INT_MAX);
    pf_put_b(flags, size, test, str);
    return (size + flags->prec + flags->blank + test);
}
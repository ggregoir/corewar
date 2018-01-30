/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_2short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:59:11 by root              #+#    #+#             */
/*   Updated: 2017/12/16 17:59:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int64 pf_2short(va_list arg)
{
    t_int64 n;

    n = va_arg(arg, int);
    n = (t_int8)n;
    return (n);
}
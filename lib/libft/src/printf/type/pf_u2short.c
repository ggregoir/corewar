/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u2short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:59:30 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:29:27 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint64	pf_u2short(va_list arg)
{
	t_uint64 n;

	n = va_arg(arg, t_uint32);
	n = (t_uint8)n;
	return (n);
}

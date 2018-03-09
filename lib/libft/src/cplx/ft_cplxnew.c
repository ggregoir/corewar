/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cplxnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:04:19 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 19:24:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cplx.h"

t_cplx	ft_cplxnew(double re, double im)
{
	t_cplx	ret;

	ret.re = re;
	ret.im = im;
	return (ret);
}
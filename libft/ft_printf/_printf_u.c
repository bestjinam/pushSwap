/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printf_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:45:30 by jinam             #+#    #+#             */
/*   Updated: 2023/12/06 16:21:21 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int _printf_u(t_temp_str *t_str, t_format *f, va_list *ap) {
  unsigned int nbr;
  int res;
  const char *base = "0123456789";

  nbr = va_arg(*ap, unsigned int);
  f->flags &= ~SPACE;
  if ((f->flags & PRECISION) == PRECISION && f->precision == 0 && nbr == 0)
    res = _nbr_d_zero_precision_zero_process(f, t_str);
  else if ((f->flags & MINUS) == MINUS)
    res = _nbr_d_minus_process(f, t_str, nbr, (char *)base);
  else if ((f->flags & ZERO) == ZERO)
    res = _nbr_d_zero_process(f, t_str, nbr, (char *)base);
  else
    res = _nbr_d_noflag_process(f, t_str, nbr, (char *)base);
  if (res == -1)
    return (-1);
  return (ft_temp_print(t_str, 1));
}

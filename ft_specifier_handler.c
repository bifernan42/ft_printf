/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:50:21 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/04 18:00:28 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_handler(t_directives s_dir, int *char_nb, va_list *adpar)
{
	if (s_dir.specifier == 'c')
		ft_putchar2(va_arg(*adpar, int), char_nb, s_dir);
	else if (s_dir.specifier == 's')
		ft_putstr2(va_arg(*adpar, char *), char_nb, s_dir);
	else if (s_dir.specifier == 'd' || s_dir.specifier == 'i')
		ft_putnbr(va_arg(*adpar, int), char_nb, s_dir);
	else if (s_dir.specifier == 'p')
		ft_puthex(va_arg(*adpar, unsigned long), 2, char_nb, s_dir);
	else if (s_dir.specifier == 'u')
		ft_putunsigned_nbr(va_arg(*adpar, unsigned int), char_nb, s_dir);
	else if (s_dir.specifier == 'x')
		ft_puthex(va_arg(*adpar, int), 0, char_nb, s_dir);
	else if (s_dir.specifier == 'X')
		ft_puthex(va_arg(*adpar, int), 1, char_nb, s_dir);
	else if (s_dir.specifier == '%')
		ft_putchar('%', char_nb);
}

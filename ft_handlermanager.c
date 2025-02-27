/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlermanager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:23 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/15 16:18:21 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_handlermanager(const char *format, int *char_count, t_directives \
*s_dir)
{
	if (*format == '\0' && !s_dir->prct_switch)
		*char_count = -1;
	else
	{
		s_dir->prct_switch = 1;
		if (*(format + 1) != '\0' || s_dir->saved_prct_count)
			ft_putchar('%', char_count);
		if (!(*(format + 1) != '\0' || s_dir->saved_prct_count == 1))
			*char_count = -1;
		if (s_dir->s_prct.is_sharp)
			ft_putchar('#', char_count);
		if (s_dir->s_prct.is_plus)
			ft_putchar('+', char_count);
		if (s_dir->s_prct.is_minus)
			ft_putchar('-', char_count);
		if (!s_dir->s_prct.is_minus && s_dir->s_prct.is_zero)
			ft_putchar('0', char_count);
		if (s_dir->s_prct.is_set_adr)
			return (s_dir->s_prct.adr);
		if (s_dir->saved_prct_count > 1 && !s_dir->s_prct.is_plus \
				&& !s_dir->s_prct.is_sharp && !s_dir->s_prct.is_minus && \
				!s_dir->s_prct.is_zero && *format == 'z')
			format++;
	}
	return ((char *)format);
}
